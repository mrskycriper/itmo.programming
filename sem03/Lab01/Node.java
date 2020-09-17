package com.mrskycriper;

public class Node
{
	String section;
	String name;
	String value;

	Node(String Section, String Name, String Value)
	{
		section = Section;
		name = Name;
		value = Value;
	}

	void PrintNode()
	{
		System.out.println(name + " from section [" + section + "] = " + value);
	}

	void PrintStringValue()
	{
		System.out.println("String value of " + name + " from section [" + section + "] = " + value);
	}

	void PrintIntValue()
	{
		System.out.println("Integer value of " + name + " from section [" + section + "] = " + Integer.parseInt(value));
	}

	void PrintDoubleValue()
	{
		System.out.println("Double value of " + name + " from section [" + section + "] = " + Double.parseDouble(value));
	}
}
