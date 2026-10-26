
int FUN_0072fb80(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cc2b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_00891268(0x48,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0072dcd0(iVar2);
  }
  local_8 = 0xffffffff;
  if (iVar2 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  pcVar4 = (char *)(in_ECX + 0x20);
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    pcVar4 = *(char **)pcVar4;
  }
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined1 *)(iVar2 + 0x44) = *(undefined1 *)(in_ECX + 0x44);
  ExceptionList = local_10;
  return iVar2;
}

