
int FUN_00729720(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_00728be0();
  iVar2 = FUN_00728be0();
  iVar3 = FUN_00728be0();
  iVar4 = FUN_00728be0();
  if (iVar4 == -1) {
    *(undefined4 *)(in_EAX + 0x38) = 0xfffffffd;
  }
  return iVar4 * 0x1000000 + iVar1 + iVar2 * 0x100 + iVar3 * 0x10000;
}

