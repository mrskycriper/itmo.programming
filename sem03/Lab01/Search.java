package com.mrskycriper;

import java.util.Vector;

public class Search
{
	static void fullSearch(Vector<Node> parsed, String sectionName, String variableName, String valueType)
	{
		int counter = 0;
		for (int i = 0; i < parsed.size(); ++i)
		{
			if (parsed.elementAt(i).section.equals(sectionName) && parsed.elementAt(i).name.equals(variableName))
			{
				switch (valueType)
				{
					case "String" -> {
						parsed.elementAt(i).PrintStringValue();
						counter++;
					}
					case "Integer" -> {
						if (Parser.isInt(parsed.elementAt(i).value))
						{
							parsed.elementAt(i).PrintIntValue();
						}
						else
						{
							System.err.println("Incorrect value type");
						}
						counter++;
					}
					case "Double" -> {
						if (Parser.isNumber(parsed.elementAt(i).value))
						{
							parsed.elementAt(i).PrintDoubleValue();
						}
						else
						{
							System.err.println("Incorrect value type");
						}
						counter++;
					}
					default -> {
						System.err.println("Incorrect value type");
						counter++;
					}
				}
			}
		}
		if (counter == 0)
		{
			System.err.println("Variable not found");
		}
	}

	static void sectionAndNameSearch(Vector<Node> parsed, String sectionName, String variableName)
	{
		int counter = 0;
		for (int i = 0; i < parsed.size(); ++i)
		{
			if (parsed.elementAt(i).section.equals(sectionName) && parsed.elementAt(i).name.equals(variableName))
			{
				parsed.elementAt(i).PrintNode();
				counter++;
			}
		}
		if (counter == 0)
		{
			System.err.println("Variable not found");
		}
	}

	static void sectionOnlySearch(Vector<Node> parsed, String sectionName)
	{
		int counter = 0;
		for (int i = 0; i < parsed.size(); ++i)
		{
			if (parsed.elementAt(i).section.equals(sectionName))
			{
				parsed.elementAt(i).PrintNode();
				counter++;
			}
		}
		if (counter == 0)
		{
			System.err.println("Section not found");
		}
	}
}
