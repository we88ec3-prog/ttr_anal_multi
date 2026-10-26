
void FUN_0080d230(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  char ****ppppcVar5;
  char *in_ECX;
  int iVar6;
  char ****ppppcVar7;
  undefined *puVar8;
  undefined1 local_54 [4];
  char ***local_50 [4];
  int local_40;
  uint local_3c;
  char local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922518;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  __splitpath(in_ECX,(char *)0x0,(char *)0x0,(char *)0x0,local_34);
  local_3c = 0xf;
  local_40 = 0;
  local_50[0] = (char ***)((uint)local_50[0] & 0xffffff00);
  FUN_00402a70("Sound/",6);
  local_8 = 0;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  ppppcVar5 = (char ****)local_50[0];
  if (local_3c < 0x10) {
    ppppcVar5 = local_50;
  }
  iVar4 = FUN_00714550(ppppcVar5,uVar2);
  if (iVar4 == 0) {
    iVar4 = __stricmp(local_34,".ogg");
    if (iVar4 == 0) {
      ppppcVar5 = (char ****)local_50[0];
      if (local_3c < 0x10) {
        ppppcVar5 = local_50;
      }
      ppppcVar7 = (char ****)local_50[0];
      if (local_3c < 0x10) {
        ppppcVar7 = local_50;
      }
      pcVar3 = (char *)((int)ppppcVar7 + local_40 + -4);
      ppppcVar7 = (char ****)local_50[0];
      if (local_3c < 0x10) {
        ppppcVar7 = local_50;
      }
      if (pcVar3 == (char *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (int)pcVar3 - (int)ppppcVar7;
      }
      if ((char *)((int)ppppcVar5 + local_40) == (char *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = ((int)ppppcVar5 + local_40) - (int)pcVar3;
      }
      FUN_00402c80(iVar4,iVar6);
      puVar8 = &DAT_00c519dc;
LAB_0080d37c:
      FUN_00401fc0(puVar8,4);
    }
    else {
      iVar4 = __stricmp(local_34,".wav");
      if (iVar4 == 0) {
        ppppcVar5 = (char ****)local_50[0];
        if (local_3c < 0x10) {
          ppppcVar5 = local_50;
        }
        ppppcVar7 = (char ****)local_50[0];
        if (local_3c < 0x10) {
          ppppcVar7 = local_50;
        }
        FUN_0080d440(local_54,(char *)((int)ppppcVar7 + local_40 + -4),
                     (char *)((int)ppppcVar5 + local_40));
        puVar8 = &DAT_00c05650;
        goto LAB_0080d37c;
      }
    }
    ppppcVar5 = (char ****)local_50[0];
    if (local_3c < 0x10) {
      ppppcVar5 = local_50;
    }
    iVar4 = FUN_00714550(ppppcVar5);
    if (iVar4 != 0) goto LAB_0080d39c;
  }
  else {
LAB_0080d39c:
    ppppcVar5 = (char ****)local_50[0];
    if (local_3c < 0x10) {
      ppppcVar5 = local_50;
    }
    __splitpath((char *)ppppcVar5,(char *)0x0,(char *)0x0,(char *)0x0,local_34);
    iVar4 = __stricmp(local_34,".ogg");
    if (iVar4 == 0) {
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      goto LAB_0080d424;
    }
    iVar4 = __stricmp(local_34,".wav");
    if (iVar4 == 0) {
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      goto LAB_0080d424;
    }
  }
  if (0xf < local_3c) {
    FUN_0089120c(local_50[0]);
  }
LAB_0080d424:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

