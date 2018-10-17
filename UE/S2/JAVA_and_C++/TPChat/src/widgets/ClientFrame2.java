package widgets;

import java.awt.Color;
import java.awt.Component;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.io.InvalidClassException;
import java.io.ObjectInputStream;
import java.io.OptionalDataException;
import java.io.StreamCorruptedException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Vector;
import java.util.logging.Logger;
import java.util.stream.Stream;

import javax.swing.AbstractAction;
import javax.swing.AbstractButton;
import javax.swing.Action;
import javax.swing.ImageIcon;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.ListCellRenderer;
import javax.swing.ListSelectionModel;
import javax.swing.TransferHandler;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultCaret;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;

import chat.Failure;
import chat.Vocabulary;
import models.AuthorListFilter;
import models.Message;
import models.Message.MessageOrder;
import models.NameSetListModel;
import javax.swing.JToolBar;
import javax.swing.KeyStroke;

import java.awt.BorderLayout;
import javax.swing.JButton;
import javax.swing.JToggleButton;
import javax.swing.Box;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import java.awt.Dimension;
import javax.swing.JPopupMenu;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;



/*
 * pour le (d)  Complétion automatique ,appuyer "fleche right"pour le completer
 * la lighe 500 (b)"fleche left" pour suprimer (c) ""flesh up"""fleche down""
 */


 class Autocomplete implements DocumentListener {

	  private static enum Mode {
	    INSERT,
	    COMPLETION
	  };
	  
	  private JTextField textField;
	  private  List<String> keywords;
	  private String completion;
	  

	  public Autocomplete(JTextField textField, List<String> keywords) {
	    this.textField = textField;
	    this.keywords = keywords;
	    Collections.sort(keywords);
	  }
	  
	  
	  @Override
	  public void changedUpdate(DocumentEvent ev) { }

	  @Override
	  public void removeUpdate(DocumentEvent ev) { }

	  @Override
	  public void insertUpdate(DocumentEvent ev) {
	    if (ev.getLength() != 1)
	      return;

	    int pos = ev.getOffset();
	    String content = null;
	    try {
	      content = textField.getText(0, pos + 1);
	    } catch (BadLocationException e) {
	      e.printStackTrace();
	    }

	    // Find where the word starts
	    int w;
	    for (w = pos; w >= 0; w--) {
	      if (!Character.isLetter(content.charAt(w))) {
	        break;
	      }
	    }

	    // Too few chars
	    if (pos - w < 2)
	      return;

	    String prefix = content.substring(w + 1).toLowerCase();
	
	    int n = Collections.binarySearch(keywords, prefix);
	    if (n < 0 && -n <= keywords.size()) {
	      String match = keywords.get(-n - 1);

	      if (match.startsWith(prefix)) {
	    	  this.completion = match.substring(pos - w);

	          // We cannot modify Document from within notification,
	          // so we submit a task that does the change later
	          SwingUtilities.invokeLater(new CompletionTask(completion, pos + 1));
	          
	      }
	    } else {
	      // Nothing found
	    
	    }
	  }



	  public class CommitAction extends AbstractAction {
		    /**
		     * 
		     */
		    private static final long serialVersionUID = 5794543109646743416L;

		    @Override
		    public void actionPerformed(ActionEvent ev) {
		     
		        int pos = textField.getSelectionEnd();
		        StringBuffer sb = new StringBuffer(textField.getText());
		        //sb.insert(pos,this.completion);
		        textField.setText(sb.toString());
		        textField.setCaretPosition(pos + 1);
		        
		        textField.replaceSelection("\t");
		      }
		    
		  }

	  private class CompletionTask implements Runnable {
	    private String completion;
	    private int position;

	    CompletionTask(String completion, int position) {
	      this.completion = completion;
	      this.position = position;
	    }

	    public void run() {
	      StringBuffer sb = new StringBuffer(textField.getText());
	      sb.insert(position, completion);
	      textField.setText(sb.toString());
	      textField.setCaretPosition(position + completion.length());
	      textField.moveCaretPosition(position);
	      
	    }
	  }

	public List<String> getKeywords() {
		// TODO Auto-generated method stub
		return this.keywords;
	}



	}
/**
 * Chat GUI v2.0 with
 * <ul>
 * <li>server message display based on {@link Message} objects rather than just
 * text but still with a different color for each user.</li>
 * <li>A text field to send new messages to the server</li>
 * <li>A List of all users which have sent a message drawn with their respective
 * color (by using a {@link ColorTextRenderer}). Selections in this list can be
 * used to filter messages</li>
 * </ul>
 * @author davidroussel
 */
public class ClientFrame2 extends AbstractClientFrame
{
		
	private int indexMessage;

	/**
	 * Serial ID (because {@link TransferHandler} is serializable)
	 */
	private static final long serialVersionUID = -7278574480208850744L;

	/**
	 * user's name (used to initialize content in the users list)
	 */
	private String clientName;

	/**
	 * List of all received messages
	 */
	private List<Message> messages;
	
	/**
	 * List of all keywords
	 */
	private final List<String> keywords;

	/**
	 * Object input stream. Used to read {@link Message}s on the
	 * {@link AbstractClientFrame#inPipe} and display these messages in the
	 * {@link AbstractClientFrame#document}
	 */
	private ObjectInputStream inOIS;

	/**
	 * Special ListModel containig only unique names and associated to the users
	 * list. This user list model should be provided when creating the
	 * {@link JList} in the UI
	 */
	private NameSetListModel userListModel;

	/**
	 * List selection model of the users list indicating which elements are
	 * selected in the users list represented by the {@link #userListModel}.
	 */
	private ListSelectionModel userListSelectionModel = null;

	/**
	 * Filter used to filter messages based users names selected in the
	 * {@link #userListSelectionModel} and {@link #userListModel}
	 */
	private AuthorListFilter authorFilter = null;

	/**
	 * Flag indicating the filtering status (on/off)
	 */
	private boolean filtering;

	Autocomplete  autoComplete ;
	/**
	 * The {@link JTextField} containing the messages to send to server
	 */
	private JTextField sendField;

	/**
	 * {@link JLabel} indicating the name of the server we're connected to
	 */
	private JLabel serverLabel;

	/**
	 * Reference to the current window (useful in internal classes)
	 */
	protected final AbstractClientFrame frameRef;

	/**
	 * Action to quit application
	 */
	private final Action quitAction = new QuitAction();

	/**
	 * Action to send message to server
	 */
	private final Action sendAction = new SendMessageAction();

	/**
	 * Action to clear messages in {@link AbstractClientFrame#document}
	 */
	private final Action clearMessagesAction = new ClearMessagesAction();

	/**
	 * Action to filter messages in the {@link AbstractClientFrame#document}
	 * based on {@link #userListModel}'s selected users in
	 * {@link #userListSelectionModel}.
	 */
	private final FilterMessagesAction filterAction = new FilterMessagesAction();

	/**
	 * Action to clear {@link #userListModel}'s {@link #userListSelectionModel}
	 * selection
	 */
	private final Action clearSelectionAction = new ClearListSelectionAction();

	/**
	 * Action to kick all {@link #userListModel}'s
	 * {@link #userListSelectionModel} selected users
	 */
	private final Action kickAction = new KickUserAction();
	
	private final Action CatchUpAction = new CatchUpAction();

	/**
	 * Action to sort all messages by date
	 */
	private final Action sortByDateAction = new SortAction(MessageOrder.DATE);

	/**
	 * Action to sort all messages by author
	 */
	private final Action sortByUserAction = new SortAction(MessageOrder.AUTHOR);

	/**
	 * Action to sort all messages by content
	 */
	private final Action sortByContentAction = new SortAction(MessageOrder.CONTENT);
	private JTextField sendTextField;

	/**
	 * Window constructor
	 * @param name user's name
	 * @param host server's name or IP address
	 * @param commonRun common run with other threads
	 * @param parentLogger parent logger
	 * @throws HeadlessException when code that is dependent on a keyboard,
	 * display, or mouse is called in an environment that does not support a
	 * keyboard, display, or mouse
	 */
	@SuppressWarnings("unchecked")
	public ClientFrame2(String name,
	                    String host,
	                    Boolean commonRun,
	                    Logger parentLogger)
	    throws HeadlessException
	{
		// ------------------------------------------------------------
		// Attributes initialization
		// ------------------------------------------------------------
		super(name, host, commonRun, parentLogger);
		frameRef = this;
		clientName = name;
		userListModel = new NameSetListModel();
		userListModel.add(clientName);
		messages = new Vector<Message>();
		keywords = new ArrayList<String>();
		indexMessage=0;
		for(int i=0;i<userListModel.getSize();i++) {
			keywords.add( userListModel.getElementAt(i).toString().toLowerCase());
			
		}
		
		
		keywords.add("testttttttt");
		
		
		inOIS = null;

		filtering = false;

		// -------------------------------------------------------------
		// Window builder part
		// -------------------------------------------------------------
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);

		JMenu mnConnections = new JMenu("Connections");
		menuBar.add(mnConnections);

		JMenuItem mntmQuit = new JMenuItem(quitAction);
		mnConnections.add(mntmQuit);

		JMenu mnMessages = new JMenu("Messages");
		menuBar.add(mnMessages);

		JMenuItem mntmClear = new JMenuItem("Clear");
		mntmClear.setAction(clearMessagesAction);
		mnMessages.add(mntmClear);

		JCheckBoxMenuItem chckbxmntmFilter = new JCheckBoxMenuItem("Filter");
		chckbxmntmFilter.setAction(filterAction);
		mnMessages.add(chckbxmntmFilter);

		JMenu mnSort = new JMenu("Sort");
		mnMessages.add(mnSort);

		JCheckBoxMenuItem chckbxmntmSortByDate = new JCheckBoxMenuItem("Sort by Date");
		chckbxmntmSortByDate.setAction(sortByDateAction);
		mnSort.add(chckbxmntmSortByDate);

		JCheckBoxMenuItem chckbxmntmSortByAuthor = new JCheckBoxMenuItem("Sort by Author");
		chckbxmntmSortByAuthor.setAction(sortByUserAction);
		mnSort.add(chckbxmntmSortByAuthor);

		JCheckBoxMenuItem chckbxmntmSortByContent = new JCheckBoxMenuItem("Sort by Content");
		chckbxmntmSortByContent.setAction(sortByContentAction);
		mnSort.add(chckbxmntmSortByContent);

		JCheckBoxMenuItem checkBoxMenuItem = new JCheckBoxMenuItem("New check item");
		mnSort.add(checkBoxMenuItem);

		JMenu mnUsers = new JMenu("Users");
		menuBar.add(mnUsers);

		JMenuItem mntmClearSelection = new JMenuItem("Clear Selection");
		mntmClearSelection.setAction(clearSelectionAction);
		mnUsers.add(mntmClearSelection);

		JMenuItem mntmKickSelected = new JMenuItem("Kick Selected");
		mntmKickSelected.setAction(kickAction);
		mnUsers.add(mntmKickSelected);

		JToolBar toolBar = new JToolBar();
		toolBar.setFloatable(false);
		getContentPane().add(toolBar, BorderLayout.NORTH);
		
		JButton btnQuit = new JButton("Quit");
		btnQuit.setHideActionText(true);
		btnQuit.setAction(quitAction);
		toolBar.add(btnQuit);
		
		Component horizontalStrut = Box.createHorizontalStrut(20);
		toolBar.add(horizontalStrut);
		
		JButton btnClear = new JButton("clear");
		btnClear.setHideActionText(true);
		btnClear.setAction(clearMessagesAction);
		toolBar.add(btnClear);
		
		JToggleButton tglbtnFilter = new JToggleButton("Filter");
		tglbtnFilter.setHideActionText(true);
		tglbtnFilter.setAction(filterAction);
		toolBar.add(tglbtnFilter);
		
		JButton btnClearSelectiom = new JButton("Clear Selectiom");
		btnClearSelectiom.setHideActionText(true);
		btnClearSelectiom.setAction(clearSelectionAction);
		toolBar.add(btnClearSelectiom);
		
		JButton btnKick = new JButton("Kick");
		btnKick.setHideActionText(true);
		btnKick.setAction(kickAction);
		toolBar.add(btnKick);
		
		JButton btnCatchup = new JButton("catchup");
		toolBar.add(btnCatchup);
		btnCatchup.setHorizontalAlignment(SwingConstants.LEFT);
		btnCatchup.setHideActionText(true);
		btnCatchup.setAction(CatchUpAction);
		
		Component horizontalGlue = Box.createHorizontalGlue();
		toolBar.add(horizontalGlue);
		
		JLabel lblServer = new JLabel("Server");
		toolBar.add(lblServer);
		
		JPanel sendPanel = new JPanel();
		getContentPane().add(sendPanel, BorderLayout.SOUTH);
		sendPanel.setLayout(new BorderLayout(0, 0));
		
		sendTextField = new JTextField();
		sendPanel.add(sendTextField);
		sendTextField.setColumns(10);
		sendTextField.setFocusTraversalKeysEnabled(false);
		
		
		 autoComplete = new Autocomplete(sendTextField, keywords);
		sendTextField.getDocument().addDocumentListener(autoComplete);

	
		//sendTextField.getInputMap().put(KeyStroke.getKeyStroke("TAB"), "commit");
		//sendTextField.getActionMap().put("commit", autoComplete.new CommitAction());
		
		/*
		 * pour le 3(b) et (c) 
		 */
		sendTextField.addKeyListener( new KeyAdapter() {
            
			public void keyPressed(KeyEvent e){
                   switch(e.getKeyCode()){
          
                
                   case KeyEvent.VK_LEFT:  sendTextField.setText(""); break;
                   case KeyEvent.VK_ENTER: {
       			sendMessage(sendTextField.getText());
       			
       			sendTextField.setText("");}break;
                   case KeyEvent.VK_UP:{
                	   if(indexMessage>0) {
                	   indexMessage--;
                	   }
                	   sendTextField.setText(messages.get(indexMessage).getContent());}break;
                   case KeyEvent.VK_DOWN:{
                	   if(indexMessage<messages.size()-1) {
                	   indexMessage++;
                	   sendTextField.setText(messages.get(indexMessage).getContent());
                	   }else {
                		   sendTextField.setText(""); 
                	   }
                	   }break;
                   case KeyEvent.VK_RIGHT:{
                	   autoComplete.new CommitAction();
                	   
                   }break;
                   default: ;
                  }
                  
                 
           }
		   });
		
	
		
		
		JButton btnSend = new JButton("Send");
		btnSend.setHideActionText(true);
		btnSend.setAction(sendAction);
		sendPanel.add(btnSend, BorderLayout.EAST);
		
		JScrollPane messagesScrollPane = new JScrollPane();
		getContentPane().add(messagesScrollPane, BorderLayout.CENTER);
		
		JTextPane textPane = new JTextPane();
		messagesScrollPane.setViewportView(textPane);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setPreferredSize(new Dimension(100, 4));
		getContentPane().add(scrollPane, BorderLayout.WEST);
		
		JList userList = new JList();
		//userList.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
		scrollPane.setViewportView(userList);
		
		JPopupMenu popupMenu = new JPopupMenu();
		addPopup(userList, popupMenu);
		
		JMenuItem mntmClearSelected = new JMenuItem("Clear Selected");
		mntmClearSelected.setAction(clearSelectionAction);
		popupMenu.add(mntmClearSelected);
		
		JMenuItem mntmKickSelected_1 = new JMenuItem("Kick Selected");
		mntmKickSelected_1.setAction(kickAction);
		popupMenu.add(mntmKickSelected_1);
		
		
		
		
		
		// -------------------------------------------------------------
		// End of Window builder part
		// -------------------------------------------------------------
		/*
		 * DONE Adds a window listener to the frame so the application can
		 * quit when window is closed
		 */
		addWindowListener(new FrameWindowListener());

		/*
		 * down autoscroll textPane to bottom
		 * 	- Get caret from textPane
		 * 	- An set its update policy to ALWAYS_UPDATE
		 */

		
	
		DefaultCaret caret = (DefaultCaret)textPane.getCaret();
		caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);

		/*
		 *  Setup document and documentStylee
		 * 	- Get Styled Document from textPane
		 * 	- Adds a new style to the document and stor it into documentStyle
		 * 	- Get foreground color from StyleConstants into defaultColor
		 */
		document = textPane.getStyledDocument();
		documentStyle = document.addStyle("defaultStyle", null);
		defaultColor = StyleConstants.getForeground(documentStyle);

		/*
		 *
		 * 
		 *  register all widgets associated to the filterAction
		 *
		
		 *
		 */
		filterAction.registerButton(chckbxmntmFilter); 
		filterAction.registerButton(tglbtnFilter); 
		
		
		/*
		 * TODO Setup List models
		 * 	- Add a new Cell Renderer to your list (a ColorTextRenderer)
		 *	//Add userListModel to your creation of the JList
		 * 	//- Get userListSelectionModel from your list
		 * 	//- Add a new List Selection Listener
		 * 	//(a UserListSelectionListener) to the userListSelectionModel
		 */

		
		userListSelectionModel = userList.getSelectionModel(); // <-- TODO replace null
		
		userListSelectionModel.addListSelectionListener(new UserListSelectionListener());
		userList.setModel(userListModel);
		userList.setCellRenderer(new ColorTextRenderer());



		/*
		 *  Create a new AuthorListFilter with userListModel and
		 * userListSelectionModel
		 */
		authorFilter = new AuthorListFilter(userListModel,userListSelectionModel); 
		
	}

	/**
	 * Client frame's thread run loop: read {@link Message} object with {@link #inOIS} and
	 * @see java.lang.Runnable#run()
	 */
	@Override
	public void run()
	{
		// DONE create an ObjectInputStream on the #inPipe to be able to read
		// Message objects
		//sendMessage("catchup");
		
		
		
		
		try
		{
			inOIS = new ObjectInputStream(inPipe);
		}
		catch (StreamCorruptedException sce)
		{
			logger.severe("ClientFrame2: "
			        + Failure.USER_INPUT_STREAM.toString()
			        + " Output Object stream: " + "stream header is incorrect, "
			        + sce.getLocalizedMessage());
			System.exit(Failure.USER_INPUT_STREAM.toInteger());
		}
		catch (IOException ioe)
		{
			logger.severe("ClientFrame2: "
			        + Failure.USER_INPUT_STREAM.toString()
			        + " IOException, " + ioe.getLocalizedMessage());
			System.exit(Failure.USER_INPUT_STREAM.toInteger());
		}

		while(commonRun.booleanValue())
		{
			Message message = null;
			// DONE Read message from inOIS
			try
			{
				message = (Message)inOIS.readObject();
			}
			catch (ClassNotFoundException | InvalidClassException |
			       StreamCorruptedException | OptionalDataException e)
			{
				logger.severe("ClientFrame2 : error reading object"
				    + e.getLocalizedMessage());
				break;
			}
			catch (IOException e)
			{
				logger.severe("ClientFrame2 : error reading object "
				    + "IO Exception : " + e.getLocalizedMessage());
				break;
			}

			// DONE Add the current message to the #messages list
			if(!message.getContent().isEmpty()) {
			messages.add(message);
		}
			
			if(message.getContent().length()>6)	{
				if(!keywords.contains(message.getContent())) {
				keywords.add(message.getContent());
				}
			}
			
			this.indexMessage = messages.size();
			// DONE Update #userListModel with evt new author
			String author = message.getAuthor();
			if ((author != null) && (author.length() > 0))
			{
				userListModel.add(author);
				if(!keywords.contains(author.toLowerCase())) {
				keywords.add(author.toLowerCase());
				}
			}
			
			autoComplete = new Autocomplete(sendTextField, keywords);
			
			//System.out.print(autoComplete.getKeywords());
			// DONE update messages
			updateMessages();
		}

		if (commonRun.booleanValue())
		{
			logger.info("ClientFrame::cleanup: changing run state at the end ... ");
			synchronized (commonRun)
			{
				commonRun = Boolean.FALSE;
			}
		}

		cleanup();
	}

	/**
	 * Cleanup: clear {@link #messages}, close {@link #inOIS} and calls
	 * super cleanup
	 * @see AbstractClientFrame#cleanup()
	 */
	@Override
	public void cleanup()
	{
		messages.clear();

		logger.info("ClientFrame2::cleanup: closing object input stream...");
		try
		{
			inOIS.close();
		}
		catch (IOException e)
		{
			logger.warning("ClientFrame2::cleanup: failed to close input stream"
			    + e.getLocalizedMessage());
		}

		super.cleanup();
	}

	/**
	 * Adds a new message at the end of {@link AbstractClientFrame#document}.
	 * The date part of the message "[yyyy/MM/dd HH:mm:ss]" should be displayed
	 * with default color whereas the "user > message" part should be displayed
	 * with user's specific color ({@link #getColorFromName(String)})
	 * @param message The message to display
	 * le message à afficher dans le
	 * {@link AbstractClientFrame#document} en modifiant au besoin le
	 * {@link AbstractClientFrame#documentStyle}
	 * @throws BadLocationException if the position to insert text is invalid
	 */
	protected void appendMessage(Message message)// throws BadLocationException
	{
		try
		{
			/*
			 * TODO Adds message date to the end of the document with default
			 * style
			 */
			if(!message.getContent().isEmpty()) {
			document.insertString(document.getLength(), message.getDate().toString(), documentStyle);

			/*
			 * TODO If message has no author (server's message) adds the
			 * message content with default style,
			 * otherwise
			 * Adds "user > content" message part with user's color
			 * obtained from AbstractClientFrame#getColorFromName
			 * followed by a new line
			 * then re-set the default style in document Style
			 * 
			 * 		document = (StyledDocument) textPane.getDocument();
					documentStyle = document.addStyle("defaultStyle", null);
					defaultColor = StyleConstants.getForeground(documentStyle);
		
			 */
			if(message.getAuthor()==null) {
				document.insertString(document.getLength(), message.toString()+"\n", documentStyle);
			}else {
				
					StyleConstants.setForeground(documentStyle,
					                             getColorFromName(message.getAuthor()));
				
			
				document.insertString(document.getLength(),message.getAuthor()+" > "+message.getContent()+"\n", documentStyle);
				
				StyleConstants.setForeground(documentStyle, defaultColor);
				
			}
		}
		
		}
		catch (BadLocationException ble)
		{
			logger.warning("ClientFrame2::appendMessage(...); Bad Location : "
			    + ble.getLocalizedMessage());
		}
	}

	/**
	 * Update all messages in document according to {@link #authorFilter}'s
	 * status and ordering set into {@link Message} class
	 */
	protected void updateMessages() // throws BadLocationException
	{
		/*
		 * TODO Clear document with remove
		 */
		try
		{
			// Clears document
			document.remove(0, document.getLength());
			//document.insertString(0, "clear", documentStyle); // <-- TODO replace
		}
		catch (BadLocationException ex)
		{
			logger.warning("ClientFrame::updateMessages: bad location"
			    + ex.getLocalizedMessage());
		}

		/*
		 * TODO Then creates a stream from messages
		 */
		Stream<Message> stream = this.messages.stream(); // <-- TODO replace

		/*
		 * TODO If Message has any orders then sort the stream
		 */
		if (Message.orderSize() > 0)
		{
			// If there is an ordering set into Message sort the stream
			stream =stream.sorted();  // <-- TODO replace
		}

		/*
		 * TODO if filtering is on then filter the stream with authorFilter
		 */
		if (filtering)
		{
			// filter sorted stream according to #authorFilter
			stream = stream.filter(authorFilter); // <-- TODO replace
		}

		/*
		 * DONE finally append all remaining messages on the stream with
		 * appenMessage(...)
		 */
		stream.forEach((Message m) -> appendMessage(m));
	}

	// ----------------------------------------------------------------
	// App related actions
	// ----------------------------------------------------------------
	/**
	 * Action to logout from server an quit application
	 */
	private class QuitAction extends AbstractAction
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = 1230763930323271538L;

		/**
		 * Constructor.
		 * Sets name, description, icons and also action's shortcut
		 */
		public QuitAction()
		{
			putValue(LARGE_ICON_KEY, new ImageIcon(ClientFrame2.class
				.getResource("/icons/disconnected-32.png")));
			putValue(SMALL_ICON, new ImageIcon(ClientFrame2.class
				.getResource("/icons/disconnected-16.png")));
			putValue(NAME, "Quit");
			putValue(SHORT_DESCRIPTION,
				"Close connection from server and quit");
		}

		/**
		 * Action performing: Clears {@link ClientFrame#serverLabel} and send
		 * {@link Vocabulary#byeCmd} to server which should terminate this frame
		 * with the {@link AbstractClientFrame#commonRun} changing to false
		 * @param e the event that triggered this action [not used]
		 */
		@Override
		public void actionPerformed(ActionEvent e)
		{
			logger.info("QuitAction: sending bye ... ");

			// TODO Complete ...
			
			//serverLabel.setText("Server");
			sendMessage(Vocabulary.byeCmd);
			commonRun=false;
			try
			{
				Thread.sleep(1000); // don't ask why
			}
			catch (InterruptedException e1)
			{
				return;
			}
		}
	}

	// ----------------------------------------------------------------
	// Message related actions
	// ----------------------------------------------------------------
	/**
	 * Action to clear {@link AbstractClientFrame#document} content
	 */
	private class ClearMessagesAction extends AbstractAction
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = -2770675891954134959L;

		/**
		 * Constructor.
		 * Sets name, description, icons and also action's shortcut
		 */
		public ClearMessagesAction()
		{
			putValue(LARGE_ICON_KEY, new ImageIcon(
				ClientFrame2.class.getResource("/icons/erase2-32.png")));
			putValue(SMALL_ICON, new ImageIcon(
				ClientFrame2.class.getResource("/icons/erase2-16.png")));
			putValue(NAME, "Clear Messages");
			putValue(SHORT_DESCRIPTION, "Clears messages in document");
		}

		/**
		 * Action performing: clears {@link AbstractClientFrame#document}
		 * content
		 * @param e the event that triggered this action [not used]
		 */
		@Override
		public void actionPerformed(ActionEvent e)
		{
			logger.info("Clear document");
			/*
			 * Clears document content
			 */
			// TODO Complete ...
			try {
				document.remove(0, document.getLength());
			} catch (BadLocationException e1) {
				// TODO Auto-generated catch block
				logger.warning("ClientFrame::ClearMessagesAction: bad location"
					    + e1.getLocalizedMessage());
			}
			/*
			 * Clears user's list
			 */
			// TODO Complete ...
			userListModel.clear();
			/*
			 * Clears recorded messages
			 */
			// TODO Complete ...
			messages.clear();
		}
	}

	/**
	 * Action to send message content to server
	 */
	private class SendMessageAction extends AbstractAction
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = -459192941860640107L;

		/**
		 * Constructor.
		 * Sets name, description, icons and also action's shortcut
		 */
		public SendMessageAction()
		{
			putValue(SMALL_ICON, new ImageIcon(
				ClientFrame2.class.getResource("/icons/sent-16.png")));
			putValue(LARGE_ICON_KEY, new ImageIcon(
				ClientFrame2.class.getResource("/icons/sent-32.png")));
			putValue(NAME, "Send Message");
			putValue(SHORT_DESCRIPTION, "Send Message to server");
		}

		/**
		 * Action performing: retreive {@link ClientFrame2#sendTextField}
		 * content
		 * if non empty and send it to server
		 * @param e the event that triggered this action [not used]
		 */
		@Override
		public void actionPerformed(ActionEvent e)
		{
			String content = sendTextField.getText();// <-- TODO replace null

			/*
			 * TODO Send sendField content to the server with sendMessage
			 * then clears sendField content
			 */
			if(content != null) {
				sendMessage(content);
				logger.info("Sent message = " + content);
				sendTextField.setText(null);
			}
		}
	}

	/**
	 * Action to filter messages according to selected users in the user's list
	 */
	private class FilterMessagesAction extends AbstractAction
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = -4990621521308404832L;

		/**
		 * Collection of widgets attached to this action.
		 * We need to keep track of various widgets triggering this action since
		 * this action is a toggle, all associated widgets should be toggled at
		 * the same time whatever widget triggered this action first
		 */
		private Collection<AbstractButton> buttons;

		/**
		 * Constructor.
		 * Initialize {@link #buttons}, Sets name, description, icons and
		 * also action's shortcut
		 */
		public FilterMessagesAction()
		{
			buttons = new ArrayList<AbstractButton>();
			putValue(SMALL_ICON, new ImageIcon(ClientFrame2.class
				.getResource("/icons/filled_filter-16.png")));
			putValue(LARGE_ICON_KEY, new ImageIcon(ClientFrame2.class
				.getResource("/icons/filled_filter-32.png")));
			putValue(NAME, "Filter Messages");
			putValue(SHORT_DESCRIPTION,
				"Filter Messages according to selected users");
		}

		/**
		 * Add a new {@link AbstractButton} to the list of widgets triggering
		 * this action
		 * @param button the button to add
		 * @return true if the button was non null and not already present in
		 * the {@link #buttons} list. False otherwise.
		 */
		public boolean registerButton(AbstractButton button)
		{
			if (button != null)
			{
				if (!buttons.contains(button))
				{
					return buttons.add(button);
				}
			}
			return false;
		}

		/**
		 * Remove a button from {@link #buttons} list.
		 * @param button the button to remove
		 * @return true if the button was non null, belonged to the
		 * {@link #buttons} list and was successfully removed from
		 * {@link #buttons}
		 */
		public boolean unregisterButton(AbstractButton button)
		{
			if (button != null)
			{
				if (buttons.contains(button))
				{
					return buttons.remove(button);
				}
			}
			return false;
		}

		/**
		 * Cleanup before destruction
		 */
		@Override
		protected void finalize()
		{
			for (AbstractButton b: buttons)
			{
				unregisterButton(b);
			}

			buttons.clear();
		}

		/**
		 * Action performing: Toggle filtering on/off then
		 * {@link ClientFrame2#updateMessages()}
		 * @param e the event that triggered this action. Used to determine
		 * button source
		 */
		@Override
		public void actionPerformed(ActionEvent e)
		{
			/*
			 * TODO Get source, then source state to see if it is selected
			 * to set new filtering status
			 */
AbstractButton button = (AbstractButton) e.getSource(); // <-- TODO replace ...
			
			boolean newFiltering = button.isSelected();  // <-- TODO replace ...
			logger.info("Filtering is " + (newFiltering ? "On" : "Off"));

			/*
			 * TODO Set Filtering on authorFilter and if update messages
			 * iff needed
			 */
			filtering = newFiltering;
			authorFilter.setFiltering(newFiltering);
			updateMessages();

			/*
			 * TODO Update all buttons associated to this action with
			 * new filtering status
			 */
			for(AbstractButton b:buttons) {
				b.setSelected(newFiltering);
			}
		}
	}

	// ----------------------------------------------------------------
	// User list related actions
	// ----------------------------------------------------------------
	/**
	 * Action to clear user's selection in users list
	 */
	private class ClearListSelectionAction extends AbstractAction
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = 6368840308418452167L;

		/**
		 * Constructor.
		 * Sets name, description, icons and also action's shortcut
		 */
		public ClearListSelectionAction()
		{
			putValue(SMALL_ICON, new ImageIcon(ClientFrame2.class
				.getResource("/icons/delete_database-16.png")));
			putValue(LARGE_ICON_KEY, new ImageIcon(ClientFrame2.class
				.getResource("/icons/delete_database-32.png")));
			putValue(NAME, "Clear selected");
			putValue(SHORT_DESCRIPTION, "Clear selected items");
		}

		/**
		 * Action performing: Clears the
		 * {@link ClientFrame2#userListSelectionModel} and also the
		 * {@link ClientFrame2#authorFilter}
		 * @param e the event that triggered this action [not used]
		 */
		@Override
		public void actionPerformed(ActionEvent e)
		{
			/*
			 * TODO Clears selection on userListSelectionModel,
			 * authorFilter and evt update messages
			 */
			userListSelectionModel.clearSelection();
			authorFilter.clear();
			updateMessages() ;
			// TODO ...
		}
	}

	/**
	 * Action for kicking (or at least try to kick) all selected users from chat
	 * server
	 */
	private class KickUserAction extends AbstractAction
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = -8029776262924225534L;

		/**
		 * Constructor.
		 * Sets name, description, icons and also action's shortcut
		 */
		public KickUserAction()
		{
			putValue(SMALL_ICON,
			         new ImageIcon(ClientFrame2.class
			             .getResource("/icons/remove_user-16.png")));
			putValue(LARGE_ICON_KEY,
			         new ImageIcon(ClientFrame2.class
			             .getResource("/icons/remove_user-32.png")));
			putValue(NAME, "Kick Selected Users");
			putValue(SHORT_DESCRIPTION, "Kick users selected in the user list");
		}

		/**
		 * Action performing: Sends a {@link Vocabulary#kickCmd} for each of the
		 * users selected in the users list
		 * @param e the event that triggered this action [not used]
		 */
		@Override
		public void actionPerformed(ActionEvent e)
		{
			/*
			 * TODO Get all selected user from userListSelectionModel
			 * and userListModel and send a kick request to the server
			 * for each of them.
			 * e.g. : "kick MyNemesis"
			 * N.B. Kick is part of Vocabulary : Vocabulary.kickCmd
			 */
			int minIndex = userListSelectionModel.getMinSelectionIndex(); // <-- TODO replace ...
			int maxIndex = userListSelectionModel.getMaxSelectionIndex(); // <-- TODO replace ...
			
			for(int i = minIndex;i<=maxIndex;i++) {
				if (userListSelectionModel.isSelectedIndex(i)) {
					sendMessage(Vocabulary.kickCmd + " " + userListModel.getElementAt(i));
					userListModel.remove(i); 
				}
			}
			// TODO ...
		}
	}
	/**
	 * Action catchup:catch tous les messages, l’intégralité des messages qu’il a enregistré
	 * @param e the event that triggered this action [not used]
	 */
	private class CatchUpAction extends AbstractAction
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = -7029776262924225534L;

		/**
		 * Constructor.
		 * Sets name, description, icons and also action's shortcut
		 */
		public CatchUpAction()
		{
			putValue(SMALL_ICON,
			         new ImageIcon(ClientFrame2.class
			             .getResource("/icons/clock-16.png")));
			putValue(LARGE_ICON_KEY,
			         new ImageIcon(ClientFrame2.class
			             .getResource("/icons/clock-32.png")));
			putValue(NAME, "Catch messages up");
			putValue(SHORT_DESCRIPTION, "here you are");
		}

		/**
		 * Action performing: Sends a {@link Vocabulary#kickCmd} for each of the
		 * users selected in the users list
		 * @param e the event that triggered this action [not used]
		 */
		@Override
		public void actionPerformed(ActionEvent e)
		{
			sendMessage("catchup");
			
		}
	}
	/**
	 * Action to sort messages according to specific ordering set into
	 * {@link Message}
	 */
	private class SortAction extends AbstractAction
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = -8690818752859664484L;

		/**
		 * Message ordering to set in this action:
		 * <ul>
		 * <li>{@link Message.MessageOrder#AUTHOR} to sort messages by
		 * author</li>
		 * <li>{@link Message.MessageOrder#DATE} to sort messages by date</li>
		 * <li>{@link Message.MessageOrder#CONTENT} to serot messages by
		 * content</li>
		 * </ul>
		 */
		private MessageOrder order;

		/**
		 * Constructor.
		 * Sets name, description, icons and also action's shortcut according to
		 * the desired ordering
		 * @param order the order to set for sorting messages
		 */
		public SortAction(MessageOrder order)
		{
			this.order = order;
			switch (order)
			{
				case DATE:
					putValue(LARGE_ICON_KEY,
					         new ImageIcon(ClientFrame2.class.getResource("/icons/clock-32.png")));
					putValue(SMALL_ICON,
					         new ImageIcon(ClientFrame2.class.getResource("/icons/clock-16.png")));
					break;
				case AUTHOR:
					putValue(LARGE_ICON_KEY,
					         new ImageIcon(ClientFrame2.class.getResource("/icons/gender_neutral_user-32.png")));
					putValue(SMALL_ICON,
					         new ImageIcon(ClientFrame2.class.getResource("/icons/gender_neutral_user-16.png")));
					break;
				case CONTENT:
					putValue(LARGE_ICON_KEY,
					         new ImageIcon(ClientFrame2.class.getResource("/icons/select_all-32.png")));
					putValue(SMALL_ICON,
					         new ImageIcon(ClientFrame2.class.getResource("/icons/select_all-16.png")));
					break;
				default:
					break;
			}
			putValue(NAME, order.toString());
			putValue(SHORT_DESCRIPTION, "Sort messages by " + order.toString());
		}

		/**
		 * Action performing: Set or unset this {@link #order} for sorting
		 * messages and update messages
		 * @param e the event that triggered this action. Used to determine
		 * if the widget triggering this action is selected or unseleced in
		 * order to set or unset sorting by adding or removing order into
		 * {@link Message} class.
		 */
		@Override
		public void actionPerformed(ActionEvent e)
		{
			/*
			 * TODO Get event source an cast it to get the selected
			 * state, then if selected add the corresponding order
			 * to Message with addOrder otherwise remove the
			 * corresponding order from Message with removeOrder
			 * And finally update messages
			 */
			AbstractButton button = (AbstractButton) e.getSource(); // <-- TODO replace ...
			boolean selected = button.isSelected();  // <-- TODO replace ...
			if (selected) {
				Message.addOrder(order);
			} else {
				Message.removeOrder(order);
			}

			// TODO ...
			updateMessages() ;
		}
	}

	/**
	 * Listener to handle selection changes in user's list.
	 * Updates the {@link ClientFrame2#authorFilter} according to currently
	 * selected users in the users list
	 */
	private class UserListSelectionListener implements ListSelectionListener
	{
		/**
		 * Method called when List selection changes
		 * @param ListSelectionEvent e the event that triggered this action
		 */
		@Override
		public void valueChanged(ListSelectionEvent e)
		{
			/*
			 * TODO
			 *down  Get first and last index of the ListSelectionEvent
			 *  //  Get the adjusting status of the event
			 *   //Get the ListSelectionModel (lsm) as the source of the event
			 *    //Then if the event is NOT adjusting then
			 * 	  //Clears authorFilter
			 * 	And add each user of the userListModel selected in the
			 * lsm to the authorFilter
			 *   ///And finally, if filtering is on updateMessages
			 *
			 * Side Note : If the list selection model is empty
			 * kickAction and clearSelectionAction should be disabled
			 * and enabled otherwise
			 */
			int firstIndex = e.getFirstIndex(); // <-- TODO replace ...
			int lastIndex = e.getLastIndex(); // <-- TODO replace ...
			boolean isAdjusting = e.getValueIsAdjusting();;  // <-- TODO replace ...
			ListSelectionModel lsm = (ListSelectionModel)e.getSource(); // <-- TODO replace ...

			/*
			 * isAdjusting remains true while events like drag n drop are
			 * still processed and becomes false afterwards.
			 */
			if (!isAdjusting)
			{
				// TODO ...
				authorFilter.clear();
				for(int i=firstIndex;i<=lastIndex;i++) {
					if (lsm.isSelectedIndex(i)) {
						authorFilter.add(userListModel.getElementAt(i));
					}
				}
				if(filtering) {
					updateMessages();
				}
			}
			if(lsm.isSelectionEmpty()) {
				kickAction.setEnabled(false);
				clearSelectionAction.setEnabled(false);
			}else {
				kickAction.setEnabled(true);
				clearSelectionAction.setEnabled(true);
			}
		}
	}

	/**
	 * Color Text renderer for drawing list's elements in colored text
	 * @author davidroussel
	 */
	private class ColorTextRenderer extends JLabel
		implements ListCellRenderer<String>
	{
		/**
		 * Serial ID because enclosing class is serializable ?
		 */
		private static final long serialVersionUID = -3133105073504656769L;

		/**
		 * Text color
		 */
		private Color color = null;

		/**
		 * Customized rendering for a ListCell with a color obtained from
		 * the hashCode of the string to display
		 * @see
		 * javax.swing.ListCellRenderer#getListCellRendererComponent(javax.swing
		 * .JList, java.lang.Object, int, boolean, boolean)
		 */
		@Override
		public Component getListCellRendererComponent(
			JList<? extends String> list, String value, int index,
			boolean isSelected, boolean cellHasFocus)
		{
			color = list.getForeground();
			if (value != null)
			{
				if (value.length() > 0)
				{
					color = frameRef.getColorFromName(value);
				}
			}
			setText(value);
			if (isSelected)
			{
				setBackground(color);
				setForeground(list.getSelectionForeground());
			}
			else
			{
				setBackground(list.getBackground());
				setForeground(color);
			}
			setEnabled(list.isEnabled());
			setFont(list.getFont());
			setOpaque(true);
			return this;
		}
	}

	/**
	 * Class redirecting the window closing event to the {@link QuitAction}
	 */
	protected class FrameWindowListener extends WindowAdapter
	{
		/**
		 * Method trigerred when window is closing
		 * @param e The Window event
		 */
		@Override
		public void windowClosing(WindowEvent e)
		{
			logger.info("FrameWindowListener::windowClosing: sending bye ... ");
			/*
			 * Calls the #quitAction if there is any
			 */
			if (quitAction != null)
			{
				quitAction.actionPerformed(null);
			}
		}
	}
	private static void addPopup(Component component, final JPopupMenu popup) {
		component.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				if (e.isPopupTrigger()) {
					showMenu(e);
				}
			}
			public void mouseReleased(MouseEvent e) {
				if (e.isPopupTrigger()) {
					showMenu(e);
				}
			}
			private void showMenu(MouseEvent e) {
				popup.show(e.getComponent(), e.getX(), e.getY());
			}
		});
	}
}
