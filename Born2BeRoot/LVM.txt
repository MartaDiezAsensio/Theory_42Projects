
LVM - Logical Volume Management
	
	It's a system of managing logical volumes, or filesystems,
	that is mush more advanced and flexible than the traditional
	method of partitioning a disk into onee or more segments and 
	formating that partition with a filesysem. 

	Logical volumes are typically created by combining or dividing
	the storage space of one or more physical volumes (PV).

	They offer great flexibility and control over storage location,
	making them well-suited for various applications, including server
	management, data centers and storage virtualization. 

LV vs partitions

	1. Dynamic resizing: Logical Volumes can be dynamically resized, 
	resizing will not require reformatting or repartitioning. 
	2. LVM software provides tools to manage logical volumes. It allows
	for creating, resizing ,deleting and moving LVs while the System 
	is running without impacting data stored on other volumes. 
	3. Striping and Mirroring.
	4. Snapshots and Backups: Backups can be taken from LVs to ensure
	data integrity and protection. Snapshots can be useful to recover
	or test as is able create point-in-time copies of the volume. 
	5. Logical Volume Groups (VGs): Collections of physical volumes that
	are managed together. They provide a higher level of abstraction. 

LV vs Containers

	A LV is a virtual partition or a loogical representation of storage 
	space that is created within a VG using LVM. It's a flexible and 
	resizable storage unit that can be used to store data or host filesystems.

	A container, on the other hand, referes to a technology used in the context
	of container-based virtualization. Containers are lightweight, isolated 
	environments that encapsulate an applicattion and it's dependenciies, allowing
	too run consistently across different computing environments.
	Containers provide an abstraction layer that enables applications to run reliably
	across diverse systems.

The Basics
	
	There are 3 concepts that LVM manages:
	1. Volume Groups
	2. Physical volumes
	3. Logical volumes

	1 - Volume Groups
	A Volume Group is a named collection off Physical and Logical 
	volumes. Typical systems only need one Volume Group to contain
	all of the physical and logical volumes on the system. 

	2 - Physical volumes
	Physical volumes correspond to disks; they are block devices
	that provide the space to store logical volumes.

	3 - Logical volumes
	Logical volumes correspond to partitions: they hold a filesystem.
	Unlike partitions, logical volumes get names rather than numbers. 

LVM (-Basic tutorial)

	Abstraction layer in top of hard disk or partitions. 
	When installing an OS in a virtual machine (in the setup) you will
	be asked if you want to Encrypt the installation (you will create 
	a key); and if you want to use LVM with the installation (This will
	setup LVM, which will allow taking snapshots and easier partition
	resizing).

