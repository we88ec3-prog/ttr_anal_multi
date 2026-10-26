
void FUN_008447d0(uint param_1)

{
  char cVar1;
  char **ppcVar2;
  char **ppcVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 ****ppppuVar7;
  int in_ECX;
  uint uVar8;
  uint unaff_EDI;
  int *piVar9;
  uint uStack_9c;
  char *pcStack_98;
  int *piStack_94;
  char *pcStack_90;
  int iStack_8c;
  undefined4 ***pppuStack_88;
  uint uStack_84;
  uint auStack_74 [2];
  undefined4 ***pppuStack_6c;
  char *pcStack_68;
  undefined4 ***local_60;
  undefined1 uStack_5c;
  uint local_58;
  undefined4 uStack_54;
  uint uStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  void *pvStack_3c;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091ea10;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  uStack_84 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  pppuStack_88 = (undefined4 ***)param_1;
  local_58 = param_1;
  iStack_8c = 0x84481a;
  FUN_007802f0();
  pppuStack_88 = &local_60;
  local_60 = (undefined4 ***)&DAT_00bf2375;
  iStack_8c = in_ECX + 0x164;
  pcStack_90 = (char *)0x84483e;
  (**(code **)(**(int **)(param_1 + 0x90) + 0xa4))();
  uStack_48 = 0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  pcStack_90 = pcStack_68;
  do {
    cVar1 = *pcStack_90;
    pcStack_90 = pcStack_90 + 1;
  } while (cVar1 != '\0');
  pcStack_90 = pcStack_90 + -(int)(pcStack_68 + 1);
  piStack_94 = (int *)pcStack_68;
  pcStack_98 = "j";
  FUN_00402a70();
  pcStack_90 = (char *)0x0;
  local_14 = (void *)0x0;
  uStack_9c = *(uint *)(param_1 + 0x88);
  piStack_94 = (int *)0x4;
  pcStack_98 = &stack0xffffff88;
  FUN_00721910();
  ppppuVar7 = (undefined4 ****)pppuStack_6c;
  if (local_58 < 0x10) {
    ppppuVar7 = &pppuStack_6c;
  }
  if ((ppppuVar7 != (undefined4 ****)0x0) && ((undefined4 ****)pppuStack_88 != (undefined4 ****)0x0)
     ) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),ppppuVar7,pppuStack_88,0);
  }
  uStack_24 = 0xffffffff;
  if (0xf < local_58) {
    FUN_0089120c(pppuStack_6c);
  }
  auStack_74[0] = *(uint *)(in_ECX + 0x178) | 0x10000;
  *(undefined4 *)(in_ECX + 0x180) = 1;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),auStack_74,4,0);
  piStack_94 = *(int **)(in_ECX + 0x174);
  piVar9 = (int *)*piStack_94;
  uVar8 = param_1;
  if (piVar9 != piStack_94) {
    do {
      pcStack_98 = (char *)piVar9[4];
      FUN_00721910(*(undefined4 *)(uVar8 + 0x88),&pcStack_98,4,0);
      param_1 = uVar8;
      if (pcStack_98 != (char *)0x0) {
        ppcVar2 = *(char ***)(uVar8 + 0x18);
        if ((&pcStack_98 < ppcVar2) && (ppcVar3 = *(char ***)(uVar8 + 0x14), ppcVar3 <= &pcStack_98)
           ) {
          if (ppcVar2 == *(char ***)(uVar8 + 0x1c)) {
            FUN_00797930();
          }
          param_1 = unaff_EDI;
          if (*(undefined4 **)(uVar8 + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(uVar8 + 0x18) =
                 *(undefined4 *)
                  (*(uint *)(uVar8 + 0x14) + ((int)&pcStack_98 - (int)ppcVar3 >> 2) * 4);
          }
        }
        else {
          if (ppcVar2 == *(char ***)(uVar8 + 0x1c)) {
            FUN_00797930();
          }
          if (*(int **)(uVar8 + 0x18) != (int *)0x0) {
            **(int **)(uVar8 + 0x18) = (int)pcStack_98;
          }
        }
        *(int *)(uVar8 + 0x18) = *(int *)(uVar8 + 0x18) + 4;
        in_ECX = iStack_8c;
      }
      if (*(char *)((int)piVar9 + 0x15) == '\0') {
        piVar4 = (int *)piVar9[2];
        if (*(char *)((int)piVar4 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x15);
          piVar9 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x15);
            piVar9 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar9[1] + 0x15);
          piVar5 = (int *)piVar9[1];
          piVar4 = piVar9;
          while ((piVar9 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar9[2]))) {
            cVar1 = *(char *)(piVar9[1] + 0x15);
            piVar5 = (int *)piVar9[1];
            piVar4 = piVar9;
          }
        }
      }
      uVar8 = param_1;
    } while (piVar9 != piStack_94);
  }
  if (*(int *)(in_ECX + 0x180) == 1) {
    pcStack_90 = "";
    (**(code **)(**(int **)(param_1 + 0x90) + 0x80))(in_ECX + 0x16c,&pcStack_90);
    uStack_54 = 0xf;
    local_58 = 0;
    pcStack_68 = (char *)((uint)pcStack_68 & 0xffffff00);
    pcVar6 = pcStack_98;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcStack_98,(int)pcVar6 - (int)(pcStack_98 + 1));
    pvStack_3c = (void *)0x1;
    uStack_9c = local_58;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&uStack_9c,4,0);
    ppppuVar7 = (undefined4 ****)local_60;
    if (uStack_4c < 0x10) {
      ppppuVar7 = &local_60;
    }
    if ((ppppuVar7 != (undefined4 ****)0x0) && (piStack_94 != (int *)0x0)) {
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),ppppuVar7,piStack_94,0);
    }
    if (0xf < uStack_4c) {
      FUN_0089120c(local_60);
    }
  }
  ExceptionList = pvStack_3c;
  __security_check_cookie(uStack_44 ^ (uint)&uStack_9c);
  return;
}

