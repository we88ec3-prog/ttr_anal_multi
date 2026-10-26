
void FUN_00868160(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 ***pppuVar3;
  int in_ECX;
  int iVar4;
  int unaff_ESI;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  char *pcStack_ac;
  int iStack_a8;
  uint uStack_a4;
  undefined4 uStack_94;
  undefined4 **ppuStack_90;
  undefined4 local_8c [3];
  undefined1 local_80;
  uint uStack_7c;
  undefined4 local_70;
  undefined4 local_6c;
  uint uStack_3c;
  void *pvStack_34;
  undefined4 uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091c308;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_94;
  uStack_a4 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  pcStack_ac = *(char **)(in_ECX + 0xc);
  local_6c = 0xf;
  local_70 = 0;
  local_80 = 0;
  pcVar2 = pcStack_ac;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iStack_a8 = (int)pcVar2 - (int)(pcStack_ac + 1);
  uStack_b0 = (undefined4 *)0x8681d4;
  FUN_00402a70();
  iStack_a8 = 0;
  local_c = 0;
  uStack_b4 = *(undefined4 *)(param_1 + 0x88);
  pcStack_ac = (char *)0x4;
  uStack_b0 = local_8c;
  local_8c[0] = local_70;
  FUN_00721910();
  pppuVar3 = (undefined4 ***)ppuStack_90;
  if (uStack_7c < 0x10) {
    pppuVar3 = &ppuStack_90;
  }
  if ((pppuVar3 != (undefined4 ***)0x0) && (unaff_ESI != 0)) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),pppuVar3,unaff_ESI,0);
  }
  local_1c = 0xffffffff;
  if (0xf < uStack_7c) {
    FUN_0089120c(ppuStack_90);
  }
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffff68,4,0);
  switch(iStack_a8) {
  case 1:
    uStack_b0 = (undefined4 *)CONCAT13(**(undefined1 **)(in_ECX + 8),(undefined3)uStack_b0);
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),(int)&uStack_b0 + 3,1,0);
    break;
  case 2:
    goto LAB_008682a2;
  case 3:
LAB_008682a2:
    uVar7 = 4;
    goto LAB_008682a9;
  case 4:
    FUN_00402b70(*(undefined4 *)(in_ECX + 8));
    uStack_2c = 1;
    FUN_00781e50();
    FUN_00402c50();
    break;
  case 5:
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffff60,8,0);
    break;
  case 6:
    uVar7 = 0xc;
    goto LAB_008682a9;
  case 7:
    uStack_94 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0xc);
    uVar7 = 0x10;
    goto LAB_008682a9;
  case 8:
    uVar7 = *(undefined4 *)(param_1 + 0x88);
    puVar5 = *(undefined4 **)(in_ECX + 8);
    puVar6 = (undefined4 *)&stack0xffffff60;
    for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    FUN_00721910(uVar7,&stack0xffffff60,0x34,0);
    break;
  case 9:
    puVar5 = *(undefined4 **)(in_ECX + 8);
    puVar6 = (undefined4 *)&stack0xffffff60;
    for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffff60,0x44,0);
    break;
  case 10:
    uVar7 = 8;
LAB_008682a9:
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&stack0xffffff60,uVar7,0);
    break;
  case 0xb:
    pcStack_ac = (char *)0x0;
    uStack_a4 = **(uint **)(in_ECX + 8);
    (**(code **)(**(int **)(param_1 + 0x90) + 0x58))(&uStack_a4,&pcStack_ac);
    FUN_00402b70(pcStack_ac);
    uStack_2c = 2;
    FUN_00781e50();
    FUN_00402c50();
  }
  ExceptionList = pvStack_34;
  __security_check_cookie(uStack_3c ^ (uint)&uStack_b4);
  return;
}

