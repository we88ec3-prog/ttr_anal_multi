
_Collvec FUN_006effc0(undefined4 param_1,char param_2)

{
  char cVar1;
  lconv *plVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  int in_ECX;
  char *pcVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char *pcVar9;
  int iVar10;
  _Collvec _Var11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009048e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  plVar2 = _localeconv();
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  local_8 = 0;
  pcVar9 = "";
  if (param_2 == '\0') {
    pcVar9 = plVar2->grouping;
  }
  __Getcoll();
  pcVar3 = pcVar9;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = pcVar3 + (1 - (int)(pcVar9 + 1));
  pcVar4 = (char *)FUN_0087dc3d(pcVar3);
  pcVar6 = pcVar4;
  for (; pcVar3 != (char *)0x0; pcVar3 = pcVar3 + -1) {
    *pcVar6 = *pcVar9;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  *(char **)(in_ECX + 8) = pcVar4;
  __Getcoll();
  pcVar6 = "false";
  pcVar3 = (char *)FUN_0087dc3d(6);
  pcVar9 = pcVar3;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pcVar9 = *pcVar6;
    pcVar9 = pcVar9 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *(char **)(in_ECX + 0x10) = pcVar3;
  __Getcoll();
  puVar8 = &DAT_00bf943c;
  puVar5 = (undefined1 *)FUN_0087dc3d(5);
  puVar7 = puVar5;
  for (iVar10 = 5; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar7 = *puVar8;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  *(undefined1 **)(in_ECX + 0x14) = puVar5;
  __Getcoll();
  *(char *)(in_ECX + 0xc) = *plVar2->decimal_point;
  _Var11 = __Getcoll();
  cVar1 = (char)*(wchar_t *)plVar2->thousands_sep;
  _Var11._Page._1_3_ = _Var11._Page._1_3_;
  _Var11._Page._0_1_ = cVar1;
  _Var11._LocaleName = (wchar_t *)plVar2->thousands_sep;
  *(char *)(in_ECX + 0xd) = cVar1;
  if (param_2 != '\0') {
    __Getcoll();
    *(undefined1 *)(in_ECX + 0xc) = 0x2e;
    _Var11 = __Getcoll();
    *(undefined1 *)(in_ECX + 0xd) = 0x2c;
  }
  ExceptionList = local_10;
  return _Var11;
}

