
/* WARNING: Type propagation algorithm not settling */

void FUN_0080cfb0(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  char *******pppppppcVar6;
  char *in_ECX;
  int iVar7;
  char *******pppppppcVar8;
  undefined *puVar9;
  undefined1 local_54 [4];
  char *******local_50 [4];
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
  local_50[0] = (char *******)((uint)local_50[0] & 0xffffff00);
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = 0;
  pppppppcVar6 = local_50[0];
  if (local_3c < 0x10) {
    pppppppcVar6 = (char *******)local_50;
  }
  iVar4 = FUN_00714550(pppppppcVar6,uVar2);
  if (iVar4 == 0) {
    iVar4 = __stricmp(local_34,".ogg");
    if (iVar4 == 0) {
      pppppppcVar6 = local_50[0];
      if (local_3c < 0x10) {
        pppppppcVar6 = (char *******)local_50;
      }
      pppppppcVar8 = local_50[0];
      if (local_3c < 0x10) {
        pppppppcVar8 = (char *******)local_50;
      }
      pcVar3 = (char *)((int)pppppppcVar8 + local_40 + -4);
      pppppppcVar8 = local_50[0];
      if (local_3c < 0x10) {
        pppppppcVar8 = (char *******)local_50;
      }
      if (pcVar3 == (char *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = (int)pcVar3 - (int)pppppppcVar8;
      }
      if ((char *)((int)pppppppcVar6 + local_40) == (char *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = ((int)pppppppcVar6 + local_40) - (int)pcVar3;
      }
      FUN_00402c80(iVar4,iVar7);
      puVar9 = &DAT_00c519dc;
LAB_0080d0f0:
      FUN_00401fc0(puVar9,4);
    }
    else {
      iVar4 = __stricmp(local_34,".wav");
      if (iVar4 == 0) {
        pppppppcVar6 = local_50[0];
        if (local_3c < 0x10) {
          pppppppcVar6 = (char *******)local_50;
        }
        pppppppcVar8 = local_50[0];
        if (local_3c < 0x10) {
          pppppppcVar8 = (char *******)local_50;
        }
        FUN_0080d440(local_54,(char *)((int)pppppppcVar8 + local_40 + -4),
                     (char *)((int)pppppppcVar6 + local_40));
        puVar9 = &DAT_00c05650;
        goto LAB_0080d0f0;
      }
    }
    pppppppcVar6 = local_50[0];
    if (local_3c < 0x10) {
      pppppppcVar6 = (char *******)local_50;
    }
    iVar4 = FUN_00714550(pppppppcVar6);
    if (iVar4 != 0) goto LAB_0080d127;
  }
  else {
LAB_0080d127:
    pppppppcVar6 = local_50[0];
    if (local_3c < 0x10) {
      pppppppcVar6 = (char *******)local_50;
    }
    __splitpath((char *)pppppppcVar6,(char *)0x0,(char *)0x0,(char *)0x0,local_34);
    iVar4 = __stricmp(local_34,".ogg");
    if (iVar4 == 0) {
      piVar5 = (int *)FUN_00891268(0x24);
      if (piVar5 == (int *)0x0) {
LAB_0080d1ae:
        piVar5 = (int *)0x0;
      }
      else {
        *piVar5 = (int)MoonSound::COGGLoader::vftable;
        piVar5[5] = 0;
        piVar5[6] = 0;
        piVar5[7] = 0;
        piVar5[8] = 0;
        piVar5[1] = 1;
      }
    }
    else {
      iVar4 = __stricmp(local_34,".wav");
      if (iVar4 != 0) goto joined_r0x0080d1fd;
      piVar5 = (int *)FUN_00891268(0xc);
      if (piVar5 == (int *)0x0) goto LAB_0080d1ae;
      *piVar5 = (int)MoonSound::CWAVLoader::vftable;
      piVar5[2] = 0;
      piVar5[1] = 0;
    }
    pppppppcVar6 = local_50[0];
    if (local_3c < 0x10) {
      pppppppcVar6 = (char *******)local_50;
    }
    iVar4 = (**(code **)(*piVar5 + 4))(pppppppcVar6);
    if (iVar4 != 0) {
      if (0xf < local_3c) {
        FUN_0089120c(local_50[0]);
      }
      goto LAB_0080d20d;
    }
    (**(code **)*piVar5)(1);
  }
joined_r0x0080d1fd:
  if (0xf < local_3c) {
    FUN_0089120c(local_50[0]);
  }
LAB_0080d20d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

