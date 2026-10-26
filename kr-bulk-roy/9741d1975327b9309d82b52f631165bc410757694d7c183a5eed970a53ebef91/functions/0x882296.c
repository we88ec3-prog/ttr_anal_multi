
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    public: static unsigned int __cdecl std::numpunct<unsigned short>::_Getcat(class
   std::locale::facet const * *,class std::locale const *)
    public: static unsigned int __cdecl std::numpunct<wchar_t>::_Getcat(class std::locale::facet
   const * *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

undefined4 Getcat(int *param_1,int *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  bVar1 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      iVar4 = *(int *)(*param_2 + 0x18);
      if (iVar4 == 0) {
        iVar4 = *param_2 + 0x1c;
      }
      uVar3 = FUN_00431550(iVar4);
      puVar2[1] = 0;
      bVar1 = true;
      *puVar2 = std::numpunct<unsigned_short>::vftable;
      Init(uVar3,1);
    }
    *param_1 = (int)puVar2;
    if (bVar1) {
      FUN_00431620();
    }
  }
  return 4;
}

