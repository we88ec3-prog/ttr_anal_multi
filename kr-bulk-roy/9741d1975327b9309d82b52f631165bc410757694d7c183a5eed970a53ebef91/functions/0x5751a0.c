
void FUN_005751a0(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void **ppvVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ce78;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(*param_1 + 4);
  ppvVar5 = &local_10;
  puVar3 = (undefined4 *)*puVar2;
  local_10 = ExceptionList;
  do {
    do {
      while( true ) {
        do {
          puVar8 = puVar3;
          ExceptionList = ppvVar5;
          if (puVar8 == puVar2) {
            iVar4 = *param_1;
            FUN_007d0240(*(undefined4 *)(*(int *)(iVar4 + 4) + 4));
            *(int *)(*(int *)(iVar4 + 4) + 4) = *(int *)(iVar4 + 4);
            *(undefined4 *)*(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 4);
            *(int *)(*(int *)(iVar4 + 4) + 8) = *(int *)(iVar4 + 4);
            *(undefined4 *)(iVar4 + 8) = 0;
            iVar4 = *param_1;
            if (iVar4 != 0) {
              local_8 = 0;
              FUN_00575d30(**(undefined4 **)(iVar4 + 4),*(undefined4 **)(iVar4 + 4));
              local_8 = 0xffffffff;
              FUN_0089120c(*(undefined4 *)(iVar4 + 4));
              FUN_0089120c(iVar4);
            }
            if ((int *)param_1[1] != (int *)0x0) {
              (**(code **)(*(int *)param_1[1] + 8))();
              param_1[1] = 0;
            }
            if ((int *)param_1[2] != (int *)0x0) {
              (**(code **)(*(int *)param_1[2] + 8))();
              param_1[2] = 0;
            }
            if ((int *)param_1[3] != (int *)0x0) {
              (**(code **)(*(int *)param_1[3] + 8))();
              param_1[3] = 0;
            }
            *param_1 = 0;
            param_1[5] = 0;
            param_1[6] = 0;
            ExceptionList = local_10;
            return;
          }
          (**(code **)(*(int *)puVar8[0xb] + 8))(uVar6);
          ppvVar5 = ExceptionList;
          puVar3 = puVar8;
        } while (*(char *)((int)puVar8 + 0x31) != '\0');
        puVar3 = (undefined4 *)puVar8[2];
        if (*(char *)((int)puVar3 + 0x31) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x31);
        puVar8 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar8 + 0x31);
          puVar3 = puVar8;
          puVar8 = (undefined4 *)*puVar8;
        }
      }
      puVar3 = (undefined4 *)puVar8[1];
    } while (*(char *)((int)puVar3 + 0x31) != '\0');
    do {
      puVar7 = puVar3;
      puVar3 = puVar7;
      if (puVar8 != (undefined4 *)puVar7[2]) break;
      puVar3 = (undefined4 *)puVar7[1];
      puVar8 = puVar7;
    } while (*(char *)((int)puVar3 + 0x31) == '\0');
  } while( true );
}

