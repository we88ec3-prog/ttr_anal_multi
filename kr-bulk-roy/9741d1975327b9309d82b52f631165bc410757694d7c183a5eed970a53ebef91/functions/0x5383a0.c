
int * FUN_005383a0(int param_1,int *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_00908469;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  local_8 = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  puVar4 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar7 = puVar4;
          if (puVar7 == puVar2) {
            ExceptionList = local_10;
            return param_2;
          }
          puVar6 = (undefined4 *)param_2[1];
          puVar4 = puVar7 + 3;
          if ((puVar4 < puVar6) && (puVar3 = (undefined4 *)*param_2, puVar3 <= puVar4)) {
            if (puVar6 == (undefined4 *)param_2[2]) {
              FUN_006d6240(uVar5);
            }
            if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
              *(undefined4 *)param_2[1] =
                   *(undefined4 *)(*param_2 + ((int)puVar4 - (int)puVar3 >> 2) * 4);
            }
          }
          else {
            if (puVar6 == (undefined4 *)param_2[2]) {
              FUN_006d6240(uVar5);
            }
            if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
              *(undefined4 *)param_2[1] = *puVar4;
            }
          }
          param_2[1] = param_2[1] + 4;
          puVar4 = puVar7;
        } while (*(char *)((int)puVar7 + 0x15) != '\0');
        puVar4 = (undefined4 *)puVar7[2];
        if (*(char *)((int)puVar4 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar7 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x15);
          puVar4 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
        }
      }
      puVar4 = (undefined4 *)puVar7[1];
    } while (*(char *)((int)puVar4 + 0x15) != '\0');
    do {
      puVar6 = puVar4;
      puVar4 = puVar6;
      if (puVar7 != (undefined4 *)puVar6[2]) break;
      puVar4 = (undefined4 *)puVar6[1];
      puVar7 = puVar6;
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  } while( true );
}

