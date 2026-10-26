
undefined4 FUN_0077be10(short *param_1)

{
  char cVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_EAX;
  short *psVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar3 = *(undefined4 **)(in_EAX + 0x10);
  puVar4 = (undefined4 *)*puVar3;
  do {
    do {
      while( true ) {
        do {
          puVar8 = puVar4;
          if (puVar8 == puVar3) {
            return 0;
          }
          psVar5 = param_1;
          do {
            sVar2 = *psVar5;
            psVar5 = psVar5 + 1;
          } while (sVar2 != 0);
          iVar6 = FUN_0044df20(0,param_1,(int)psVar5 - (int)(param_1 + 1) >> 1);
          if (iVar6 == 0) {
            return puVar8[4];
          }
          puVar4 = puVar8;
        } while (*(char *)((int)puVar8 + 0x15) != '\0');
        puVar4 = (undefined4 *)puVar8[2];
        if (*(char *)((int)puVar4 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar8 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar8 + 0x15);
          puVar4 = puVar8;
          puVar8 = (undefined4 *)*puVar8;
        }
      }
      puVar4 = (undefined4 *)puVar8[1];
    } while (*(char *)((int)puVar4 + 0x15) != '\0');
    do {
      puVar7 = puVar4;
      puVar4 = puVar7;
      if (puVar8 != (undefined4 *)puVar7[2]) break;
      puVar4 = (undefined4 *)puVar7[1];
      puVar8 = puVar7;
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  } while( true );
}

