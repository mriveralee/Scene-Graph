/*******************************/
|	   Michael Rivera	|
|	     CIS 277		|
|	        HW3		|
|     Graphical User Interface	|
|    	HELLO PUPPET v 1.0	|
/********************************/


/////////////////////
****** GUIDE ********
/////////////////////

On the base load, the user is presented with a character I constructed. From the user has two available node modes which are
changeable via the top-righthand slider: 'Creator' and 'Editor.'
	# 'Creator' Mode allows the user to add and delete Nodes to the scene graph. The user need only select a node in the Scene graph tree that which
	  they wish to be the parent of the soon to be added node or if they want this node to be deleted. 
		- ADDING A NODE: The user should set the values for all of the sliders name (to appear in the tree), ScaleX, ScaleY, TranslateX, TranslateY,
		 		 Red color, Green Color, Blue Color, and rotation. If the user wants the node to have geometry they must switch the geometry control
				 to 'yes' and choose a number of sides. NOTE: If the user tries to select a number of sides < 3, the node added will automatically update to have
				 3 sides. This is because no shape exists for < 3 sides. Also, the user can edit any of this information after they've created the node later. 
				 To complete the add process, simply click 'ADD.' The node will now appear in the tree where you selected it to and appear on screen if it was 
				 designated to have geometry.
		- Deleting A Node: Once a node is selected in the tree and the mode is set to 'creator' mode, clicking 'DELETE' will remove the node from the tree.
				   If the node has children these children will then be pairs with the parents of the node to be deleted, taking the appropriate transformations
				   as specified by the scene graph and remain on the screen. The Scene Graph Tree View will also update their current relationships in the tree.
				   NOTE: You CANNOT DELETE THE MAIN ROOT NODE. This was a design choice. IN order to maintain the structure of the scene graph this was necessary.
				   You can however, edit this node's transformations matrices and or name.
	# 'Editor' Mode is your best friend if you need to change properties of specific nodes in the trees such as adjusting transformation matrices. 
		- Once selecting a Node in editor mode, the node's values will populate in the display boxex and sliders. You need only change these values for the
		  changes to appear. They will occur live in the OpenGL window. Additionally, you can rename the node in the Scene graph tree viewer live via the name box.
		  Notice as you change the name to what ever your heart fancies, it will continually update in the tree.
 		- NOTE (forgot to include this in the readme) for deleting non-leaf nodes they will appear to disappear if they end up switching their 
		parent to the Root ('Character Node') This is because the transformations through their former parents scale them appropriately. So when you delete 
		the current parent the nodes will become very small and translate to the origin. Change to editor mode and adjust the size by clicking on the node. 
		Then adjust the scale. You will see it appear :).
	# EXTRA CREDIT:
		- Expandable/Collapsable Nodes - these are evident in the Scene Graph Tree Viewer
		- Deleting None leaf nodes and reassigning their children - give it a try. Switch into editor mode and delete the 'Neck.' The Head Node will now become a child
		  of the Character. Its children nodes will remain being its children.
		- Other Usability -> 
			--The editor mode and creator mode. It prevents mishaps with changing values if you delete a Node with a scale of 100 it will node carry over
		 	   to the next node you click.
			-- Menu Bar: 
				= File: includes a reset graph button and a quit option.
				= About: includes my name, course and project title.
			-- Gave the project a title :).
			-- Clean Intuitive design (or at least I would like to think so ;
			-- Ability to add custom geometry or no geometry at all. Let user add solely transformation matrices.
			-- Specifying number of sides for added geometry and color.

////////////////////////////
****** Difficulties ********
////////////////////////////

I faced the following difficulties in this project:

	# When in 'EDITOR' Mode andonClick of a treeWidgetItem in the Scene Graph Tree Viewer there was a tremendous
	amount of difficulty in populating the values of all the slides and boxes for translateX,Y, ScaleX,Y, Rotation,
	and all of the color sliders to the values of the clicked Node. It was particularly difficult because it required 
	doing a cascading slot that passed values on to the nextslider or double box. If i emitted the signals all from 
	the view on click it changed the values in the process, causing them to appear incorrect. The implementation now 
	causes a single signal to be sent from the view to the ScaleX box with all the necessary values of the currently 
	clicked node. This then sends a signal with te values to the ScaleY, then that does to TransY and so on. Not sure 
	if this was the best way to do it but it suffices.
	
	# My initial design of the passing values simply used the value changed signals for many of the boxes but when i added the
	onClick of a node in the tree view, it would apply transformations to the character even if they weren't edited. I had to fix this
	by constructing my own slot that would send the appropriate value and a boolean to tell the glWidget whether to accept changes being made.

	# Deleting non-leaf nodes and reassigning their children- much more difficult than I thought and not intuitive.
	  Actually Delete in general was hell. But it comes off very clean in my implementation ;).

	# Current unresolved difficulties-> I currently am not utilizing the delete pointer function in my code when you a delete a node. I haven't set up
	 a destructor for the node class because when I did was erasing my heap == BIG NO NO and MANY ERRORS. I have to fix this in the next implementation.
	

////////////////////////////
****** TESTING *************
////////////////////////////

	# Much of my program was tested using cout statements to the console to test the passing of values. Additionally, much of it was tested through trial and error.
	Each time a feature was added, I checked whether the old functionality remained consistent and if the values of nodes were correct on updates etc.
	# Not sure of any other bugs, but I am sure they are some so feedback is welcomed!

ENJOY!
-Mike	


