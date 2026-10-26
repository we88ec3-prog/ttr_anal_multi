
void FUN_00872260(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *unaff_EDI;
  uint in_stack_00000018;
  char local_21c [520];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00913868;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  pcVar4 = param_1;
  if (in_stack_00000018 < 0x10) {
    pcVar4 = (char *)&param_1;
  }
  iVar2 = -(int)pcVar4;
  do {
    cVar1 = *pcVar4;
    pcVar4[(int)(local_21c + iVar2)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  unaff_EDI[4] = 0;
  if (0xf < (uint)unaff_EDI[5]) {
    unaff_EDI = (undefined4 *)*unaff_EDI;
  }
  *(undefined1 *)unaff_EDI = 0;
  local_14 = uVar3;
  pcVar4 = _strtok(local_21c,"[ \t]");
  while (pcVar4 != (char *)0x0) {
    pcVar5 = pcVar4;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(pcVar4,(int)pcVar5 - (int)(pcVar4 + 1));
    pcVar4 = _strtok((char *)0x0,"[ \t]");
  }
  if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1,uVar3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

