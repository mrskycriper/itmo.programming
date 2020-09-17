package com.mrskycriper;

import java.util.Scanner;
import java.util.Vector;

public class Main
{

	public static void main(String[] args)
	{
		String fileIn;
		Scanner in = new Scanner(System.in);
		Vector<Node> parsed = null;
		int action = 4;
		String sectionName;
		String variableName;
		String valueType;
		while (action != 5)
		{
			switch (action)
			{
				case 4 -> {
					Menu.showFileSelect();
					fileIn = in.next();
					try
					{
						parsed = Parser.Process(fileIn);
					}
					catch (Exception error)
					{
						System.err.println("File not found");
						return;
					}
					if (parsed == null)
					{
						System.err.println("Wrong file format");
						return;
					}
					Menu.showInfo(fileIn, parsed.size());
				}
				case 3 -> {
					Menu.showFullSearch();
					sectionName = in.next();
					variableName = in.next();
					valueType = in.next();
					Search.fullSearch(parsed, sectionName, variableName, valueType);
				}
				case 2 -> {
					Menu.showSectionAndNameSearch();
					sectionName = in.next();
					variableName = in.next();
					Search.sectionAndNameSearch(parsed, sectionName, variableName);
				}
				case 1 -> {
					Menu.showSectionOnlySearch();
					sectionName = in.next();
					Search.sectionOnlySearch(parsed, sectionName);
				}
			}

			Menu.showActions();
			action = in.nextInt();
			while (action < 1 || action > 5)
			{
				System.err.println("Wrong action, try again");
				action = in.nextInt();
			}
		}
	}
}
