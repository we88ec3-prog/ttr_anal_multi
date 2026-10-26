
undefined4 * FUN_006fab50(int param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar3 = (undefined4 *)*param_2;
  iVar4 = *(int *)(param_1 + 0x10);
  bVar2 = *(byte *)(iVar4 + 0x14);
  do {
    if ((puVar3 == (undefined4 *)0x0) || (param_3 == 0)) {
      return param_2;
    }
    if (*(char *)(puVar3 + 1) == '\b') {
      FUN_006fab50(param_1,puVar3 + 0x1a,0xfffffffd);
    }
    if ((byte)((bVar2 ^ 3) & (*(byte *)((int)puVar3 + 5) ^ 3)) != 0) {
      *(byte *)((int)puVar3 + 5) = *(byte *)((int)puVar3 + 5) & 0xf8 | *(byte *)(iVar4 + 0x14) & 3;
      param_2 = puVar3;
      goto switchD_006fabdf_default;
    }
    *param_2 = *puVar3;
    if (puVar3 == *(undefined4 **)(iVar4 + 0x1c)) {
      *(undefined4 *)(iVar4 + 0x1c) = *puVar3;
    }
    switch(*(undefined1 *)(puVar3 + 1)) {
    case 4:
      piVar1 = (int *)(*(int *)(param_1 + 0x10) + 4);
      *piVar1 = *piVar1 + -1;
      iVar5 = puVar3[3] + 0x11;
      goto LAB_006fac44;
    case 5:
      FUN_006f9a10();
      break;
    case 6:
      FUN_006fd9e0(param_1);
      break;
    case 7:
      iVar5 = puVar3[4] + 0x18;
      goto LAB_006fac44;
    case 8:
      FUN_006f7460();
      break;
    case 9:
      FUN_006fd950();
      break;
    case 10:
      piVar1 = puVar3 + 4;
      if ((int *)puVar3[2] != piVar1) {
        *(int *)(puVar3[5] + 0x10) = *piVar1;
        *(undefined4 *)(*piVar1 + 0x14) = puVar3[5];
      }
      iVar5 = 0x20;
LAB_006fac44:
      FUN_00700880(param_1,puVar3,iVar5,0);
    }
switchD_006fabdf_default:
    puVar3 = (undefined4 *)*param_2;
    param_3 = param_3 + -1;
  } while( true );
}

