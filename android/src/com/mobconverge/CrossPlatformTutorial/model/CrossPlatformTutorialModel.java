package com.mobconverge.CrossPlatformTutorial.model;

public class CrossPlatformTutorialModel {	
	public static class Person {
		private String fname;
		private String lname;
		private int id;
		
		public Person(String fname, String lname) {
			this.fname = fname;
			this.lname = lname;
		}
		
		public Person(int id, String fname, String lname) {
			this.id = id;
			this.fname = fname;
			this.lname = lname;
		}
		
		public void setFirstName(String fname) { this.fname = fname; }
		public void setLastName(String lname) { this.lname = lname; }
		
		public String getFirstName() { return fname; }
		public String getLastName() { return lname; }
		
		public int getId() { return id; }
		
		public native void persistToDisk();
	}
	
	public native Person[] getAllPersons();
}
