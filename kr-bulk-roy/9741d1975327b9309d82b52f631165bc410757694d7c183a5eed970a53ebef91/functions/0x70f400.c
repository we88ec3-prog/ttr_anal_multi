
void FUN_0070f400(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if (*(int *)(in_EAX + 0x10) != 0x28) {
    if (*(int *)(in_EAX + 0x10) != 0x11d) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
    FUN_0070dd50(param_1);
    return;
  }
  iVar1 = *(int *)(in_EAX + 4);
  *(int *)(in_EAX + 8) = iVar1;
  if (*(int *)(in_EAX + 0x20) == 0x11f) {
    uVar2 = FUN_006ffec0(in_EAX + 0x18);
    *(undefined4 *)(in_EAX + 0x10) = uVar2;
  }
  else {
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    *(undefined4 *)(in_EAX + 0x20) = 0x11f;
  }
  FUN_0070fc00();
  if (*(int *)(in_EAX + 0x10) == 0x29) {
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
    if (*(int *)(in_EAX + 0x20) != 0x11f) {
      *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
      *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
      *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
      *(undefined4 *)(in_EAX + 0x20) = 0x11f;
      FUN_007122a0();
      return;
    }
    uVar2 = FUN_006ffec0(in_EAX + 0x18);
    *(undefined4 *)(in_EAX + 0x10) = uVar2;
    FUN_007122a0();
    return;
  }
  if (iVar1 == *(int *)(in_EAX + 4)) {
    FUN_0070d750();
  }
  iVar3 = _iscntrl(0x28);
  if (iVar3 == 0) {
    uVar2 = *(undefined4 *)(in_EAX + 0x34);
    pcVar5 = "%c";
  }
  else {
    uVar2 = *(undefined4 *)(in_EAX + 0x34);
    pcVar5 = "char(%d)";
  }
  uVar2 = FUN_006f7c30(uVar2,pcVar5,0x28);
  iVar3 = _iscntrl(0x29);
  if (iVar3 == 0) {
    uVar4 = *(undefined4 *)(in_EAX + 0x34);
    pcVar5 = "%c";
  }
  else {
    uVar4 = *(undefined4 *)(in_EAX + 0x34);
    pcVar5 = "char(%d)";
  }
  uVar4 = FUN_006f7c30(uVar4,pcVar5,0x29);
  FUN_006f7c30(*(undefined4 *)(in_EAX + 0x34),"\'%s\' expected (to close \'%s\' at line %d)",uVar4,
               uVar2,iVar1);
                    /* WARNING: Subroutine does not return */
  FUN_006ff130();
}

