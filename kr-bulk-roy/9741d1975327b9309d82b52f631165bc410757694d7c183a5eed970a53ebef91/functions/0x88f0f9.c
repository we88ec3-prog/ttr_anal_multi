
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    public: static unsigned int __cdecl std::collate<char>::_Getcat(class std::locale::facet const *
   *,class std::locale const *)
   
   Library: Visual Studio 2010 Release */

uint __cdecl std::collate<char>::_Getcat(facet **param_1,locale *param_2)

{
  bool bVar1;
  bool bVar2;
  facet *pfVar3;
  undefined4 *puVar4;
  uint uVar5;
  _Collvec _Var6;
  
  bVar2 = false;
  bVar1 = false;
  if ((param_1 != (facet **)0x0) && (*param_1 == (facet *)0x0)) {
    pfVar3 = (facet *)FUN_00891268(0x10);
    if (pfVar3 == (facet *)0x0) {
      pfVar3 = (facet *)0x0;
    }
    else {
      puVar4 = (undefined4 *)locale::name(param_2);
      if (0xf < (uint)puVar4[5]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_00431550(puVar4);
      *(undefined4 *)(pfVar3 + 4) = 0;
      bVar2 = true;
      bVar1 = true;
      *(undefined ***)pfVar3 = vftable;
      _Var6 = __Getcoll();
      *(_Collvec *)(pfVar3 + 8) = _Var6;
    }
    *param_1 = pfVar3;
    if (bVar1) {
      FUN_00431620();
    }
    if (bVar2) {
      FUN_00402f30(1,0);
    }
  }
  uVar5 = FUN_0089dbbc();
  return uVar5;
}

