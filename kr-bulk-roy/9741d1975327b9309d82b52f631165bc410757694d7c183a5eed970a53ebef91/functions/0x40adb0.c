
int FUN_0040adb0(int *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int local_8;
  
  puVar2 = *(undefined4 **)param_1[0x2f];
  do {
    do {
      while( true ) {
        do {
          puVar5 = puVar2;
          if (puVar5 == (undefined4 *)param_1[0x2f]) {
            return 0;
          }
          if (puVar5[4] == param_2) {
            piVar4 = param_1 + 0x2a;
            FUN_0082ef00(puVar5 + 3);
            if (local_8 != param_1[0x2b]) {
              if (*(int *)(puVar5[4] + 0x80) != 0) {
                *(undefined1 *)(*(int *)(puVar5[4] + 0x80) + 200) = 0;
              }
              (**(code **)(*param_1 + 0x74))(*(undefined4 *)(local_8 + 0x10));
              if (*(int **)(local_8 + 0x10) != (int *)0x0) {
                (**(code **)(**(int **)(local_8 + 0x10) + 0x1c))(1);
                *(undefined4 *)(local_8 + 0x10) = 0;
              }
              FUN_007b6890(piVar4,&local_8,local_8);
            }
            FUN_007b6890(param_1 + 0x2e,&param_1,puVar5);
            return param_2;
          }
          puVar2 = puVar5;
        } while (*(char *)((int)puVar5 + 0x15) != '\0');
        puVar2 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar2 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar2 + 0x15);
        puVar5 = (undefined4 *)*puVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar2 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      puVar2 = (undefined4 *)puVar5[1];
    } while (*(char *)((int)puVar2 + 0x15) != '\0');
    do {
      puVar3 = puVar2;
      puVar2 = puVar3;
      if (puVar5 != (undefined4 *)puVar3[2]) break;
      puVar2 = (undefined4 *)puVar3[1];
      puVar5 = puVar3;
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  } while( true );
}

