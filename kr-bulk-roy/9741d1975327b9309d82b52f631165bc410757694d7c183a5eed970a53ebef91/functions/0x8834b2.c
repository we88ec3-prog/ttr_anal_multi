
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    public: static unsigned int __cdecl std::moneypunct<unsigned short,1>::_Getcat(class
   std::locale::facet const * *,class std::locale const *)
    public: static unsigned int __cdecl std::moneypunct<wchar_t,1>::_Getcat(class std::locale::facet
   const * *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

undefined4 Getcat(int *param_1,int *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  bVar1 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    puVar2 = (undefined4 *)FUN_00891268(0x34);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      iVar3 = *(int *)(*param_2 + 0x18);
      if (iVar3 == 0) {
        iVar3 = *param_2 + 0x1c;
      }
      uVar4 = FUN_00431550(iVar3);
      puVar2[1] = 0;
      bVar1 = true;
      *(undefined1 *)(puVar2 + 10) = 1;
      *puVar2 = std::_Mpunct<unsigned_short>::vftable;
      Init(uVar4,1);
      *puVar2 = std::moneypunct<unsigned_short,1>::vftable;
    }
    *param_1 = (int)puVar2;
    if (bVar1) {
      FUN_00431620();
    }
  }
  return 3;
}

