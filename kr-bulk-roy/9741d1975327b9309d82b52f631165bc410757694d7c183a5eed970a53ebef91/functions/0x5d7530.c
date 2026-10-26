
void FUN_005d7530(void)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f284;
  local_14 = ExceptionList;
  if (*(int *)(in_ECX + 0x25c) == 0) {
    return;
  }
  ExceptionList = &local_14;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_20 = *(undefined4 *)(in_ECX + 0x254);
  FUN_008438c0(&local_20);
  if (local_1c == DAT_00f8d91c) {
    ExceptionList = local_14;
    return;
  }
  if (*(int *)(local_1c + 0x10) == 0) {
    ExceptionList = local_14;
    return;
  }
  iVar3 = *(int *)(*(int *)(local_1c + 0x10) + 0x54);
  if (iVar3 == 0) {
    ExceptionList = local_14;
    return;
  }
  if (*(int *)(iVar3 + 4) != 0) {
    FUN_00404ba0();
    iVar2 = FUN_004d42c0();
    if (iVar2 == 0) {
      uVar5 = 0x196;
      FUN_005854b0(0x196,0,0);
      uVar5 = FUN_00585330(uVar5);
      uVar4 = 0x1c1;
      FUN_005854b0(0x1c1,uVar5);
      uVar5 = FUN_00585330(uVar4);
      FUN_00404b10(0xca,uVar5);
      ExceptionList = local_14;
      return;
    }
  }
  switch(*(undefined4 *)(iVar3 + 8)) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x1b:
  case 0x20:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    uVar5 = *(undefined4 *)(in_ECX + 0x24c);
    uVar4 = *(undefined4 *)(in_ECX + 0x248);
    FUN_00409560(uVar4,uVar5);
    iVar3 = FUN_004dc700(uVar4,uVar5);
    if (iVar3 == 0) {
      iVar3 = FUN_00891268(0x24);
      if (iVar3 != 0) {
        FUN_00753e70(0xf4422,*(undefined4 *)(in_ECX + 0x250),0,0);
      }
    }
    else if ((*(short **)(iVar3 + 0x54) == (short *)0x0) || (**(short **)(iVar3 + 0x54) == 0)) {
      local_1c = FUN_00891268(0x24);
      local_c = 2;
      if (local_1c == 0) goto LAB_005d76df;
      uVar5 = FUN_004dc850();
      FUN_00753e70(0xf4422,*(undefined4 *)(in_ECX + 0x250),*(undefined4 *)(iVar3 + 0x30),uVar5);
      local_c = 0xffffffff;
    }
    else {
      local_1c = FUN_00891268(0x24);
      local_c = 1;
      if (local_1c == 0) {
LAB_005d76df:
        local_c = 0xffffffff;
      }
      else {
        puVar1 = *(undefined2 **)(iVar3 + 0x54);
        uVar5 = FUN_004dc850();
        FUN_00753e70(0xf4422,*puVar1,*(undefined1 *)(puVar1 + 1),uVar5);
        local_c = 0xffffffff;
      }
    }
    break;
  default:
    goto switchD_005d765b_caseD_5;
  case 0x1d:
    iVar3 = FUN_00891268(0x20);
    if (iVar3 != 0) {
      FUN_00753d00(1,1);
    }
  }
  FUN_00404aa0();
  FUN_00750020();
switchD_005d765b_caseD_5:
  ExceptionList = local_14;
  return;
}

