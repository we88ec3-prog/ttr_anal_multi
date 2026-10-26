
facet * FUN_007841f0(int *param_1)

{
  facet *pfVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  facet *pfVar6;
  bad_cast local_28 [12];
  _Lockit local_1c [4];
  _Lockit local_18 [4];
  facet *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907b18;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  std::_Lockit::_Lockit(local_1c,0);
  pfVar1 = DAT_00fe3204;
  local_8 = 0;
  local_14 = DAT_00fe3204;
  if (DAT_00fe7274 == 0) {
    std::_Lockit::_Lockit(local_18,0);
    if (DAT_00fe7274 == 0) {
      DAT_00f8c848 = DAT_00f8c848 + 1;
      DAT_00fe7274 = DAT_00f8c848;
    }
    FUN_0087dd6f(uVar4);
  }
  piVar3 = param_1;
  uVar2 = DAT_00fe7274;
  iVar5 = *param_1;
  if (DAT_00fe7274 < *(uint *)(iVar5 + 0xc)) {
    pfVar6 = *(facet **)(*(int *)(iVar5 + 8) + DAT_00fe7274 * 4);
    if (pfVar6 == (facet *)0x0) goto LAB_00784280;
LAB_0078429e:
    if (pfVar6 != (facet *)0x0) goto LAB_00784307;
  }
  else {
    pfVar6 = (facet *)0x0;
LAB_00784280:
    if (*(char *)(iVar5 + 0x14) == '\0') goto LAB_0078429e;
    iVar5 = FUN_0087ded7();
    if (uVar2 < *(uint *)(iVar5 + 0xc)) {
      pfVar6 = *(facet **)(*(int *)(iVar5 + 8) + uVar2 * 4);
      goto LAB_0078429e;
    }
  }
  pfVar6 = pfVar1;
  if (pfVar1 == (facet *)0x0) {
    iVar5 = FUN_00784530(&local_14,piVar3);
    pfVar6 = local_14;
    if (iVar5 == -1) {
      std::bad_cast::bad_cast(local_28,"bad cast");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_28,&DAT_00c85874);
    }
    DAT_00fe3204 = local_14;
    std::_Lockit::_Lockit((_Lockit *)&param_1,0);
    if (*(int *)(pfVar6 + 4) != -1) {
      *(int *)(pfVar6 + 4) = *(int *)(pfVar6 + 4) + 1;
    }
    FUN_0087dd6f();
    std::locale::facet::_Facet_Register(pfVar6);
  }
LAB_00784307:
  local_8 = 0xffffffff;
  FUN_0087dd6f(uVar4);
  ExceptionList = local_10;
  return pfVar6;
}

