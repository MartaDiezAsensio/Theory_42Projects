
Devian vs CentOS

	They are both popular Linux distributions but have some differences
	in terrms of characteristics, target audience, release cycle, package
	management and community support. 

	Debian is primarily desktop orienetated (general use) whereas CentOS 
	is designed for servers and focuses on stability. It's commonly used 
	inn enterprise environment. 

	Rocky was created as a community-driven replacement for CentOS after 
	the shift in the CentOS projet's direction. CentOS was runned by the 
	Red Hat Enterprrise Linux (RHEL). 


SELinux and DNF 

	SELinux stands for Security Enhanced Linux and is a security archittecture
	for Linux Systems that allows administrators to have more control over
	who can access the system. It's a framework implemented in the Linux Kernel.
	
	SELinux definese access conttrrols for the applications, processes and 
	files on a system. When an application or process, known as subject,
	makes a request to access an object, like a file, SElinux checks with
	an access vector cache (AVC), where permissions are cached dor subjects
	and objects.

	DNF (Dandified YUM) is a package manager used in some linux distributions
	(CentOS 8 included and) and is the sucessoorr to YUM package (Yellow Updater,
	Modified). Is a software package manager that installs, updates and removes
	packages on Fedora (another linux distribution).

AppArmor

	AppArmor is a Mandatory Access Control (MAC) Framework. When ennabled,
	AppArmo confines programs according to a set of rules that specify
	what files a given program can access. This proactive approach helps
	protect the system against known and unknown vulnerabilities. 

	In summary, is a Linux Application Security System.

SELinux vs AppArmor

	They are both securiry frameworks but they have different apprroaches and
	focuses. These are some of the diferences:
		1. Madatory vs Ddiscretionary Access Control. 
			SElinux uses mandatory access control (MAC). It enforces strict access
			control policies based on securrity labels assigned to system resources.
			SElinux polices define what actions are allowed dor each labeled object, 
			regardless of user permissions.

			AppArmor uses Discretary access control (DAC) model. It works by creating 
			profiles that specify the allowed actions for specific applications or
			processes. Permissions can be modified by adinistrators oor users.
		2. Level of Granularity
			SELinux offers fine-grained access control and can enforce 
			restrictions at a highly granular level. It assigns security labels to 
			various system resources, such as files, processes, and network ports, 
			allowing for precise control over access and actions.
			
			AppArmor provides a coarser level of granularity compared to SELinux.
			It focuses primarily on application-level access control and defines policies 
			based on the application's behavior, file paths, or network access. It may not 
			offer the same level of detail and control over system resources as SELinux.

APT vs Aptitude

	APT (Advanced Package Tool) and Aptitude are both package management tools used in 
	Debian-based Linux distributions. While they serve similar purposes, there are some 
	differences between the two:
		1. Interface: APT is command-line tool, Aptitude has also a graphical interface. 
		2. Dependency Resolution: Aptitude is considered to have more advanced dependenciies
		handling capabilities. 
		3. Package Management Operations
		4. Search Functionality
		5. Package Recommendations and Suggestions
		6. Additional features
	In summary, APT is a command-line package management tool focused on simplicity and efficiency. 
	Aptitude, while also a command-line tool, provides a more interactive and user-friendly 
	interface with advanced dependency handling capabilities. Both tools have their strengths 
	and can be used for managing packages on Debian-based systems.


Password Policy

	Debian, being a popular Linux distribution, allows system administrators to customize the 
	password policy according to their specific requirements. By default, Debian uses the 
	pam_unix module, which provides password authentication and enforces certain password policies.
	Here are some aspects of the password policy typically found in Debian:
		1. Password Length
		2. Complexity
		3. Password Expiration
		4. Password History
		5. Account Lockout
		6. Password Strength Assestment
