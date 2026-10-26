
void FUN_005c7230(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 8);
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar5 = puVar3;
          if (puVar5 == puVar2) {
            FUN_007370d0(*(undefined4 *)(*(int *)(param_1 + 8) + 4));
            *(int *)(*(int *)(param_1 + 8) + 4) = *(int *)(param_1 + 8);
            *(undefined4 *)*(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 8);
            *(int *)(*(int *)(param_1 + 8) + 8) = *(int *)(param_1 + 8);
            *(undefined4 *)(param_1 + 0xc) = 0;
            return;
          }
          (**(code **)(*(int *)puVar5[10] + 0x2c))();
          (**(code **)(*(int *)puVar5[10] + 0x24))();
          if ((int *)puVar5[10] != (int *)0x0) {
            (**(code **)(*(int *)puVar5[10] + 0x1c))(1);
            puVar5[10] = 0;
          }
          puVar3 = puVar5;
        } while (*(char *)((int)puVar5 + 0x2d) != '\0');
        puVar3 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar3 + 0x2d) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x2d);
        puVar5 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x2d);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      puVar3 = (undefined4 *)puVar5[1];
    } while (*(char *)((int)puVar3 + 0x2d) != '\0');
    do {
      puVar4 = puVar3;
      puVar3 = puVar4;
      if (puVar5 != (undefined4 *)puVar4[2]) break;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar4;
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  } while( true );
}

