
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    public: static unsigned int __cdecl std::collate<unsigned short>::_Getcat(class
   std::locale::facet const * *,class std::locale const *)
    public: static unsigned int __cdecl std::collate<wchar_t>::_Getcat(class std::locale::facet
   const * *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

void Getcat(int *param_1,locale *param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  _Collvec _Var5;
  
  bVar2 = false;
  bVar1 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    puVar3 = (undefined4 *)FUN_00891268(0x10);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)std::locale::name(param_2);
      if (0xf < (uint)puVar4[5]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_00431550(puVar4);
      puVar3[1] = 0;
      bVar2 = true;
      bVar1 = true;
      *puVar3 = std::collate<unsigned_short>::vftable;
      _Var5 = __Getcoll();
      *(_Collvec *)(puVar3 + 2) = _Var5;
    }
    *param_1 = (int)puVar3;
    if (bVar1) {
      FUN_00431620();
    }
    if (bVar2) {
      FUN_00402f30(1,0);
    }
  }
  FUN_0089dbbc();
  return;
}

