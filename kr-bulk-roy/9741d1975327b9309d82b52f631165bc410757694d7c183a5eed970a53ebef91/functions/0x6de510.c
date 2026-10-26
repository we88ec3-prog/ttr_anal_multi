
facet * FUN_006de510(int *param_1)

{
  uint uVar1;
  facet *pfVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  facet *pfVar6;
  facet *local_24;
  _Lockit local_20 [4];
  _Lockit local_1c [4];
  bad_cast local_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0090a878;
  local_c = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffcc;
  ExceptionList = &local_c;
  std::_Lockit::_Lockit(local_1c,0);
  pfVar2 = DAT_00fe31a8;
  local_4 = 0;
  local_24 = DAT_00fe31a8;
  if (DAT_00f8c84c == 0) {
    std::_Lockit::_Lockit(local_20,0);
    if (DAT_00f8c84c == 0) {
      DAT_00f8c848 = DAT_00f8c848 + 1;
      DAT_00f8c84c = DAT_00f8c848;
    }
    FUN_0087dd6f(uVar4);
  }
  piVar3 = param_1;
  uVar1 = DAT_00f8c84c;
  iVar5 = *param_1;
  if (DAT_00f8c84c < *(uint *)(iVar5 + 0xc)) {
    pfVar6 = *(facet **)(*(int *)(iVar5 + 8) + DAT_00f8c84c * 4);
    if (pfVar6 == (facet *)0x0) goto LAB_006de5a4;
LAB_006de5c2:
    if (pfVar6 != (facet *)0x0) goto LAB_006de631;
  }
  else {
    pfVar6 = (facet *)0x0;
LAB_006de5a4:
    if (*(char *)(iVar5 + 0x14) == '\0') goto LAB_006de5c2;
    iVar5 = FUN_0087ded7();
    if (uVar1 < *(uint *)(iVar5 + 0xc)) {
      pfVar6 = *(facet **)(*(int *)(iVar5 + 8) + uVar1 * 4);
      goto LAB_006de5c2;
    }
  }
  pfVar6 = pfVar2;
  if (pfVar2 == (facet *)0x0) {
    iVar5 = FUN_006de450(&local_24,piVar3);
    pfVar6 = local_24;
    if (iVar5 == -1) {
      std::bad_cast::bad_cast(local_18,"bad cast");
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_18,&DAT_00c85874);
    }
    DAT_00fe31a8 = local_24;
    std::_Lockit::_Lockit((_Lockit *)&param_1,0);
    if (*(int *)(pfVar6 + 4) != -1) {
      *(int *)(pfVar6 + 4) = *(int *)(pfVar6 + 4) + 1;
    }
    FUN_0087dd6f();
    std::locale::facet::_Facet_Register(pfVar6);
  }
LAB_006de631:
  local_4 = 0xffffffff;
  FUN_0087dd6f(uVar4);
  ExceptionList = local_c;
  return pfVar6;
}

