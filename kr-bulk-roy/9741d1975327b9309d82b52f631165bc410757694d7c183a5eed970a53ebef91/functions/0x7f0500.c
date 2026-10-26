
/* WARNING: Removing unreachable block (ram,0x007f066f) */
/* WARNING: Removing unreachable block (ram,0x007f0788) */

void FUN_007f0500(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  char *pcVar8;
  int in_ECX;
  char *pcVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092062c;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x128) != 0) {
    uVar5 = DAT_00fd94d8 & 1;
    *(undefined4 *)(in_ECX + 0x128) = 0;
    if (uVar5 == 0) {
      DAT_00fd94d8 = DAT_00fd94d8 | 1;
      local_8 = 0;
      FUN_007b5430(uVar7);
      _atexit((_func_4879 *)&LAB_00bce660);
    }
    local_8 = 0xffffffff;
    FUN_007b5f30(in_ECX + 0x40);
    puVar2 = *(undefined4 **)(in_ECX + 0x110);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      pcVar9 = (char *)(in_ECX + 0xb4);
      if (0xf < *(uint *)(in_ECX + 200)) {
        pcVar9 = *(char **)pcVar9;
      }
      pcVar8 = pcVar9;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
      local_8 = 1;
      FUN_00401fc0(&DAT_00c4fe14,4);
      if ((uint)puVar3[9] < 0x10) {
        pcVar9 = (char *)(puVar3 + 4);
      }
      else {
        pcVar9 = (char *)puVar3[4];
      }
      pcVar8 = pcVar9;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00401fc0(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
      if (puVar3[0xb] != 0) {
        puVar3[0xb] = 0;
        if ((DAT_00fd94d8 & 1) == 0) {
          DAT_00fd94d8 = DAT_00fd94d8 | 1;
          local_8._0_1_ = 2;
          FUN_007b5430();
          _atexit((_func_4879 *)&LAB_00bce660);
          local_8 = CONCAT31(local_8._1_3_,1);
        }
        FUN_007b67e0(&DAT_00fd9420);
      }
      local_8 = 0xffffffff;
      if (*(char *)((int)puVar3 + 0x31) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x31) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x31);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x31);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x31);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x31);
            puVar6 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    if (*(undefined4 **)(in_ECX + 0x124) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x124))(1);
      *(undefined4 *)(in_ECX + 0x124) = 0;
    }
    *(undefined4 *)(in_ECX + 0x120) = 0;
    if (*(undefined4 **)(in_ECX + 0x11c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x11c))(1);
      *(undefined4 *)(in_ECX + 0x11c) = 0;
    }
    pcVar9 = (char *)(in_ECX + 0xb4);
    if (0xf < *(uint *)(in_ECX + 200)) {
      pcVar9 = *(char **)pcVar9;
    }
    pcVar8 = pcVar9;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
    local_8 = 3;
    FUN_00401fc0("mesh/",5);
    if (*(uint *)(in_ECX + 0x58) < 0x10) {
      pcVar9 = (char *)(in_ECX + 0x44);
    }
    else {
      pcVar9 = *(char **)(in_ECX + 0x44);
    }
    pcVar8 = pcVar9;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar7 ^ (uint)&stack0xfffffffc);
  return;
}

