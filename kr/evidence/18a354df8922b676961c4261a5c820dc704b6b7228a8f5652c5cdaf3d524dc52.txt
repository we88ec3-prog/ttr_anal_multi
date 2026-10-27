
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00546850(char *param_1)

{
  float fVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int local_1c;
  char local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ef9e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = 0;
  cVar3 = '\0';
  local_1c = 0;
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  if (DAT_00fb9005 == '\x01') {
LAB_005468ee:
    local_1c = -1;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 1;
      FUN_006d0750(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    if (DAT_00fb9005 == '\x02') goto LAB_005468ee;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 2;
    FUN_006d0750(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  if (DAT_00fb9006 == '\x01') {
LAB_00546965:
    local_1c = local_1c + 1;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 3;
      FUN_006d0750(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    if (DAT_00fb9006 == '\x02') goto LAB_00546965;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 4;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  if (DAT_00fb9007 == '\x01') {
LAB_005469dc:
    iVar4 = -1;
  }
  else {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 5;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    if (DAT_00fb9007 == '\x02') goto LAB_005469dc;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 6;
    FUN_006d0750();
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  if (DAT_00fb9008 != '\x01') {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 7;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    if (DAT_00fb9008 != '\x02') goto LAB_00546a54;
  }
  iVar4 = iVar4 + 1;
LAB_00546a54:
  local_8 = 0xffffffff;
  if (local_1c == -1) {
    cVar3 = -0x80;
    if (iVar4 == -1) {
      cVar3 = -0x60;
    }
    else if (iVar4 == 1) {
      cVar3 = '`';
    }
  }
  else if (local_1c == 1) {
    cVar3 = '\0';
    if (iVar4 == -1) {
      cVar3 = -0x20;
    }
    else if (iVar4 == 1) {
      cVar3 = ' ';
    }
  }
  else if (iVar4 == -1) {
    cVar3 = -0x40;
  }
  else if (iVar4 == 1) {
    cVar3 = '@';
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 8;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  fVar1 = *(float *)(DAT_00fb76e8 + 0x20);
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  local_18 = (char)(int)ROUND(_DAT_00fb8824 * fVar1);
  if ((iVar4 == 0) && (local_1c == 0)) {
    ExceptionList = local_10;
    return 0;
  }
  *param_1 = cVar3 + local_18;
  ExceptionList = local_10;
  return 1;
}

