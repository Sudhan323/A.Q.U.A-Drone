# A.Q.U.A-Drone
Code submission for AQUA Drone for EYIC2020 Competition. Project ID : 594

The folder "Latex" has the required latex files for creating the proposal.
The folder "Final Proposal" in "Latex" folder consist of the final porposal of the project idea.

The folder "Application of Drone"  consist of two sub folders.
Both of them consist of python programs developed for the application of the underwater drone. 
Crack Detection folder has an filename "CrackDetectionInPipe" which is a python code to find the crack present in a pipe which is placed underwater.
Fish detection is another application of A.Q.U.A Drone.
It detects the presence of fish in the video from the drone and draws rectangular box around the fish.

The packages for both the programs are numpy and cv2.
The fish detection program converts the "Test_ROV_video_h264_decim.mp4" file into "video_Modified.mp4" file
It uses the cascade filter for detection of fishes.

There is a sketchup model of the drone in the folder 3D model with some snap shots.

The arduino code consist of the code that is used to run the drone using joystick.
