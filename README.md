# FileReferenceMacros
File Macro Header (mainly for reference pch files for multiple pch in single project)
based on https://stackoverflow.com/questions/30438911/how-to-get-a-visual-studio-macro-value-into-a-pre-processor-directive

Refer to MFCApp or MFCTextViewer for some 

Example .vcxproj needed file blocks(for pch.h inside project folder assuming with project being in github folder):
  <PropertyGroup Label="UserMacros">
    <GithubFolder Condition="Exists('C:/UserFiles/GitHub/')">C:/UserFiles/GitHub/</GithubFolder>
    <GithubFolder Condition="!Exists('C:/UserFiles/GitHub/')">..</GithubFolder>
    <AppFolder>$(GithubFolder)AppName/</AppFolder>
    <PCHHeader>$(AppFolder)pch.h</PCHHeader>
    <PCHOutput>$(AppFolder)$(Configuration)/pch.pch</PCHOutput>
    <RawPCH>$(PCHHeader)</RawPCH>
  </PropertyGroup>
  <ItemDefinitionGroup Label="Windows Item Definition Group">
    <!-- Condition="'$(Platform)'=='Win32' Or '$(Platform)'=='x64'"-->
    <ClCompile>
      <PreprocessorDefinitions Condition="'$(Configuration)'=='Debug'">PCHFile=$(RawPCH);WIN32;_WINDOWS;_DEBUG;%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <PreprocessorDefinitions Condition="'$(Configuration)'=='Release'">PCHFile=$(RawPCH);NDEBUG;WIN32;_WINDOWS;%(PreprocessorDefinitions)</PreprocessorDefinitions>
    </ClCompile>
  </ItemDefinitionGroup>
  <ItemGroup>
    <BuildMacro Include="RawPCH">
      <Value>$(RawPCH)</Value>
    </BuildMacro>
  </ItemGroup>

Example pch.h File Contents:
#ifndef Pch_H
#define Pch_H

#include "../FileReferenceMacros/FileReferenceMacros.h"
#define PrecompileFile   MacroToString(PCHFile)//Referencing "pch.h" file

// add headers that you want to be precompiled here
#include "MFCFramework.h"

#endif

Example pch.cpp File Contents:
//source file corresponding to the pre-compiled header
#include PrecompileFile//#include "pch.h"