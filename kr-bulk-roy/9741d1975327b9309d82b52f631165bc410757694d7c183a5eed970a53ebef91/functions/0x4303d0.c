
void FUN_004303d0(undefined4 param_1,char param_2)

{
  char cVar1;
  lconv *plVar2;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  wchar_t *pwVar5;
  _Collvec _Var6;
  uint uStack_44;
  _Collvec local_30;
  lconv *local_28;
  _Collvec local_24;
  char *local_1c;
  uchar local_18 [4];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  uchar local_8 [4];
  
  local_8[0] = 0xff;
  local_8[1] = 0xff;
  local_8[2] = 0xff;
  local_8[3] = 0xff;
  puStack_c = &LAB_00904c20;
  local_10 = ExceptionList;
  uStack_44 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_44;
  ExceptionList = &local_10;
  local_28 = _localeconv();
  local_8[0] = '\0';
  local_8[1] = '\0';
  local_8[2] = '\0';
  local_8[3] = '\0';
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (param_2 == '\0') {
    local_1c = local_28->grouping;
  }
  else {
    local_1c = "";
  }
  __Getcoll();
  pcVar3 = local_1c;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = pcVar3 + (1 - (int)(local_1c + 1));
  local_24._LocaleName = (wchar_t *)FUN_0087dc3d(pcVar3);
  pwVar5 = local_24._LocaleName;
  for (; pcVar3 != (char *)0x0; pcVar3 = pcVar3 + -1) {
    *(char *)pwVar5 = *local_1c;
    pwVar5 = (wchar_t *)((int)pwVar5 + 1);
    local_1c = local_1c + 1;
  }
  *(wchar_t **)(in_ECX + 8) = local_24._LocaleName;
  local_24 = __Getcoll();
  uVar4 = FUN_004302b0("false",0,&local_24);
  *(undefined4 *)(in_ECX + 0x10) = uVar4;
  _Var6 = __Getcoll();
  local_24 = _Var6;
  uVar4 = FUN_004302b0(&DAT_00bf943c,0,&local_24);
  *(undefined4 *)(in_ECX + 0x14) = uVar4;
  local_30 = __Getcoll();
  plVar2 = local_28;
  local_18[0] = *local_28->decimal_point;
  local_1c = (char *)0x0;
  local_28 = (lconv *)0x0;
  __Mbrtowc((wchar_t *)&local_1c,(char *)local_18,1,(mbstate_t *)&local_28,(_Cvtvec *)&local_30);
  *(undefined2 *)(in_ECX + 0xc) = local_1c._0_2_;
  local_30 = __Getcoll();
  local_18[0] = *plVar2->thousands_sep;
  local_1c = (char *)0x0;
  local_28 = (lconv *)0x0;
  __Mbrtowc((wchar_t *)&local_1c,(char *)local_18,1,(mbstate_t *)&local_28,(_Cvtvec *)&local_30);
  *(undefined2 *)(in_ECX + 0xe) = local_1c._0_2_;
  if (param_2 != '\0') {
    local_30 = __Getcoll();
    param_2 = '.';
    local_1c = (char *)0x0;
    local_28 = (lconv *)0x0;
    __Mbrtowc((wchar_t *)&local_1c,&param_2,1,(mbstate_t *)&local_28,(_Cvtvec *)&local_30);
    *(undefined2 *)(in_ECX + 0xc) = local_1c._0_2_;
    local_30 = __Getcoll();
    param_2 = ',';
    local_1c = (char *)0x0;
    local_28 = (lconv *)0x0;
    __Mbrtowc((wchar_t *)&local_1c,&param_2,1,(mbstate_t *)&local_28,(_Cvtvec *)&local_30);
    *(undefined2 *)(in_ECX + 0xe) = local_1c._0_2_;
  }
  ExceptionList = local_10;
  return;
}

