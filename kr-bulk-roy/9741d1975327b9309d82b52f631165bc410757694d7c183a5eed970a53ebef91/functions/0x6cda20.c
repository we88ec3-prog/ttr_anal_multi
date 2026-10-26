
void FUN_006cda20(void)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  byte *in_EDX;
  bool bVar6;
  undefined4 local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919c38;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (in_EDX != (byte *)0x0) {
    pcVar5 = "Custom";
    pbVar3 = in_EDX;
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_006cda80:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_006cda85;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < (byte)pcVar5[1];
      if (bVar1 != pcVar5[1]) goto LAB_006cda80;
      pbVar3 = pbVar3 + 2;
      pcVar5 = pcVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_006cda85:
    if (iVar4 != 0) {
      local_1c = 0xf;
      local_20 = 0;
      local_30 = local_30 & 0xffffff00;
      pbVar3 = in_EDX;
      do {
        bVar1 = *pbVar3;
        pbVar3 = pbVar3 + 1;
      } while (bVar1 != 0);
      FUN_0040b310(in_EDX);
      local_8 = 0;
      FUN_006cef50(&local_34);
      if (0xf < local_1c) {
        FUN_0089120c(local_30,uVar2);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

