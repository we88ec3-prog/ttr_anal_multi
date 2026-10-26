
/* Library Function - Single Match
    private: static void __cdecl std::locale::facet::_Facet_Register(class std::locale::facet *)
   
   Library: Visual Studio 2010 Release */

void __cdecl std::locale::facet::_Facet_Register(facet *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = DAT_00f8c83c;
    puVar1[1] = param_1;
  }
  DAT_00f8c83c = puVar1;
  return;
}

