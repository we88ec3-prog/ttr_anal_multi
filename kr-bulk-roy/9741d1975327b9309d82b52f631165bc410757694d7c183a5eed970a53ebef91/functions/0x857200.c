
undefined4 FUN_00857200(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_EAX;
  int iVar7;
  int unaff_EDI;
  undefined4 local_10 [3];
  
  local_10[0] = *(undefined4 *)(in_EAX + 8);
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),local_10,4,0);
  if (unaff_EDI != 0) {
    puVar3 = *(undefined4 **)(in_EAX + 4);
    puVar4 = (undefined4 *)*puVar3;
    while (puVar4 != puVar3) {
      if (puVar4 + 3 != (undefined4 *)0x0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar4 + 3,4,0);
      }
      puVar5 = puVar4 + 4;
      if (puVar5 != (undefined4 *)0x0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar5,4,0);
      }
      if (puVar4 + 5 != (undefined4 *)0x0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar4 + 5,4,0);
      }
      piVar1 = puVar4 + 6;
      if (piVar1 != (int *)0x0) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),piVar1,4,0);
      }
      switch(*puVar5) {
      case 0:
      case 4:
      case 5:
      case 6:
        iVar7 = 4;
        break;
      case 1:
      case 7:
        iVar7 = 8;
        break;
      case 2:
        iVar7 = 0xc;
        break;
      case 3:
        iVar7 = 0x10;
        break;
      default:
        iVar7 = 0;
      }
      if ((puVar4 + 7 != (undefined4 *)0x0) && (*piVar1 * iVar7 != 0)) {
        FUN_00721910(*(undefined4 *)(param_1 + 0x88),puVar4 + 7,*piVar1 * iVar7,0);
      }
      if (*(char *)((int)puVar4 + 0x21) == '\0') {
        puVar5 = (undefined4 *)puVar4[2];
        if (*(char *)((int)puVar5 + 0x21) == '\0') {
          cVar2 = *(char *)((int)*puVar5 + 0x21);
          puVar4 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
          while (cVar2 == '\0') {
            cVar2 = *(char *)((int)*puVar5 + 0x21);
            puVar4 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
          }
        }
        else {
          cVar2 = *(char *)((int)puVar4[1] + 0x21);
          puVar6 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
          while ((puVar4 = puVar6, cVar2 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
            cVar2 = *(char *)((int)puVar4[1] + 0x21);
            puVar6 = (undefined4 *)puVar4[1];
            puVar5 = puVar4;
          }
        }
      }
    }
    return 1;
  }
  return 0;
}

