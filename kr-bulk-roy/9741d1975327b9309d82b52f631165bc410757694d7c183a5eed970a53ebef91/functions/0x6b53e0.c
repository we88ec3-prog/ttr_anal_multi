
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006b53e0(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  int local_2c;
  int local_28;
  undefined2 local_24;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093286a;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = 0;
  do {
    local_14 = uVar2;
    if (*(char *)((int)in_ECX + iVar3 + 0x1d8) == '\0') {
      if (iVar3 == 0) {
        if ((DAT_00fe5b2c & 1) == 0) {
          DAT_00fe5b2c = DAT_00fe5b2c | 1;
          local_8 = iVar3;
          FUN_00584c40(&DAT_00fe5b0c);
          _atexit(FUN_00bcf370);
        }
        local_8 = 0xffffffff;
        local_28 = 0x196;
        FUN_005740f0(&local_28);
        if (local_2c == DAT_00fe5b10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        if ((DAT_00fe5b2c & 1) == 0) {
          DAT_00fe5b2c = DAT_00fe5b2c | 1;
          local_8 = 1;
          FUN_00584c40(&DAT_00fe5b0c);
          _atexit(FUN_00bcf370);
          local_8 = 0xffffffff;
        }
        local_2c = 0x5f;
        FUN_005740f0(&local_2c);
        if (local_28 == DAT_00fe5b10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        if (*(uint *)(local_28 + 0x24) < 8) {
          iVar3 = local_28 + 0x10;
        }
        else {
          iVar3 = *(int *)(local_28 + 0x10);
        }
        if ((DAT_00faadd0 & 1) == 0) {
          DAT_00faadd0 = DAT_00faadd0 | 1;
          local_8 = 2;
          FUN_0074d990();
          _atexit((_func_4879 *)&LAB_00bccc70);
          local_8 = 0xffffffff;
        }
        FUN_007532b0(&DAT_00f94810,iVar3,0,0);
        goto LAB_006b551e;
      }
      break;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_21 = (undefined1)in_ECX[0x76];
  local_20 = *(undefined1 *)((int)in_ECX + 0x1d9);
  local_24 = 0x16;
  local_1f = *(undefined1 *)((int)in_ECX + 0x1da);
  local_1e = *(undefined1 *)((int)in_ECX + 0x1db);
  local_1d = (undefined1)in_ECX[0x77];
  local_1c = *(undefined1 *)((int)in_ECX + 0x1dd);
  local_1b = *(undefined1 *)((int)in_ECX + 0x1de);
  local_1a = *(undefined1 *)((int)in_ECX + 0x1df);
  local_19 = (undefined1)in_ECX[0x78];
  local_18 = *(undefined1 *)((int)in_ECX + 0x1e1);
  local_22 = 0;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_24,0xd,uVar2);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_28 = 0x34;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_28,4);
  }
  (**(code **)(*in_ECX + 0xd4))();
LAB_006b551e:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

