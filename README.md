This project implements a Student Course Enrollment Assistant that helps universities and students manage course planning while ensuring that all prerequisites are satisfied before a course is taken.
The system uses structures, dynamic memory, arrays, pointers, and graph algorithms (DFS/BFS) to validate course dependencies and detect scheduling issues.

⸻

🎯 Objectives
	•	Store a course catalog with:
	•	Course codes
	•	Prerequisites
	•	Credit hours
	•	Semester offered
	•	Allow a student to build a semester plan.
	•	Automatically check:
	•	Missing prerequisites
	•	Cyclical dependencies
	•	Schedule conflicts
	•	Credit overload
	•	Suggest remedial or alternative courses.
	•	Use adjacency lists or adjacency matrices to represent prerequisite graphs.
	•	Apply DFS/BFS to detect unmet prerequisites and cycles.

⸻

🛠️ Features Implemented

1.⁠ ⁠Course Catalog Management
	•	Each course is stored using a structure containing:
	•	Course ID
	•	Name
	•	Credits
	•	Prerequisite list
	•	Offered semester

2.⁠ ⁠Student Semester Planner
	•	The student selects desired courses.
	•	System checks:
	•	Whether prerequisites are completed.
	•	Whether selected courses overlap in timing.
	•	Total credits do not exceed allowed limit.

3.⁠ ⁠Prerequisite Graph
	•	Prerequisite relationships are stored as a directed graph.
	•	Uses:
	•	Adjacency lists (array of pointers) OR
	•	Adjacency matrix
	•	Graph traversal using DFS / BFS to:
	•	Detect missing prerequisites
	•	Detect circular prerequisites

4.⁠ ⁠Credit Computation & Conflict Detection
	•	Calculates total semester credits.
	•	Warns if credit load exceeds permissible limit.
	•	Optionally checks for time-slot clashes.

5.⁠ ⁠Dynamic Memory
	•	malloc(), calloc(), and free() used for:
	•	Course lists
	•	Graph allocations
	•	Student plans

Here is screenshot of output:
<img width="1280" height="889" alt="image" src="https://github.com/user-attachments/assets/a4b57ed4-d7de-44ce-b4b6-bd495f13976a" />
