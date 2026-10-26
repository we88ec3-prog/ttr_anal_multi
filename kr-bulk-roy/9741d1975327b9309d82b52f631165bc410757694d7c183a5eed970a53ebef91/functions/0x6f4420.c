
undefined4 FUN_006f4420(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  char *pcVar7;
  undefined8 uVar8;
  
  FID_conflict__wprintf("root base : %x, count : %d\n",**(undefined4 **)(param_1 + 0x28));
  FID_conflict__wprintf("(top:%d)\n");
  iVar4 = 1;
  if (0xf < (int)(*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) & 0xfffffff0U)) {
    do {
      puVar1 = (undefined4 *)FUN_006f50f0();
      if (puVar1 == &DAT_00c0bfc8) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = puVar1[2];
      }
      switch(uVar2) {
      case 1:
        piVar3 = (int *)FUN_006f50f0();
        if ((piVar3[2] == 0) || ((piVar3[2] == 1 && (*piVar3 == 0)))) {
          pcVar7 = "false";
        }
        else {
          pcVar7 = "true";
        }
        puVar1 = (undefined4 *)FUN_006f50f0();
        if ((puVar1 == &DAT_00c0bfc8) || (iVar5 = puVar1[2], iVar5 == -1)) {
LAB_006f4533:
          uVar8 = CONCAT44(pcVar7,"no value");
          pcVar7 = "(%d:%s)%s ";
        }
        else {
LAB_006f4545:
          uVar8 = CONCAT44(pcVar7,(&PTR_DAT_00c0be1c)[iVar5]);
          pcVar7 = "(%d:%s)%s ";
        }
        break;
      case 2:
      case 5:
      case 6:
      case 7:
      case 8:
        piVar3 = (int *)FUN_006f50f0();
        switch(piVar3[2]) {
        case 2:
        case 7:
          piVar3 = (int *)FUN_006f50f0();
          if (piVar3[2] == 2) {
            iVar5 = *piVar3;
          }
          else if (piVar3[2] == 7) {
            iVar5 = *piVar3 + 0x18;
          }
          else {
            iVar5 = 0;
          }
          break;
        default:
          iVar5 = 0;
          break;
        case 5:
        case 6:
        case 8:
          iVar5 = *piVar3;
        }
        puVar1 = (undefined4 *)FUN_006f50f0();
        if ((puVar1 == &DAT_00c0bfc8) || (puVar1[2] == -1)) {
          uVar8 = CONCAT44(iVar5,"no value");
          pcVar7 = "(%d:%s)%x ";
        }
        else {
          uVar8 = CONCAT44(iVar5,(&PTR_DAT_00c0be1c)[puVar1[2]]);
          pcVar7 = "(%d:%s)%x ";
        }
        break;
      case 3:
        puVar1 = (undefined4 *)FUN_006f50f0();
        if ((puVar1 == &DAT_00c0bfc8) || (puVar1[2] == -1)) {
          pcVar7 = "no value";
        }
        else {
          pcVar7 = (&PTR_DAT_00c0be1c)[puVar1[2]];
        }
        fVar6 = (float10)FUN_006f5320();
        FID_conflict__wprintf("(%d:%s)%f ",iVar4,pcVar7,(double)fVar6);
        goto LAB_006f470a;
      case 4:
        piVar3 = (int *)FUN_006f50f0();
        if (piVar3[2] == 4) {
LAB_006f45db:
          pcVar7 = (char *)(*piVar3 + 0x10);
        }
        else {
          iVar5 = FUN_006fb5d0();
          if (iVar5 != 0) {
            if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <=
                *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
              FUN_006fb3a0();
            }
            piVar3 = (int *)FUN_006f50f0();
            goto LAB_006f45db;
          }
          pcVar7 = (char *)0x0;
        }
        puVar1 = (undefined4 *)FUN_006f50f0();
        if (puVar1 == &DAT_00c0bfc8) goto LAB_006f4533;
        iVar5 = puVar1[2];
        if (iVar5 != -1) goto LAB_006f4545;
        uVar8 = CONCAT44(pcVar7,"no value");
        pcVar7 = "(%d:%s)%s ";
        break;
      case 0xffffffff:
      case 0:
        puVar1 = (undefined4 *)FUN_006f50f0();
        if ((puVar1 == &DAT_00c0bfc8) || (puVar1[2] == -1)) {
          FID_conflict__wprintf("(%d:%s) ",iVar4);
        }
        else {
          FID_conflict__wprintf("(%d:%s) ",iVar4);
        }
        goto LAB_006f470a;
      default:
        piVar3 = (int *)FUN_006f50f0();
        switch(piVar3[2]) {
        case 2:
        case 7:
          piVar3 = (int *)FUN_006f50f0();
          if (piVar3[2] == 2) {
            iVar5 = *piVar3;
          }
          else if (piVar3[2] == 7) {
            iVar5 = *piVar3 + 0x18;
          }
          else {
            iVar5 = 0;
          }
          break;
        default:
          iVar5 = 0;
          break;
        case 5:
        case 6:
        case 8:
          iVar5 = *piVar3;
        }
        puVar1 = (undefined4 *)FUN_006f50f0();
        if (puVar1 == &DAT_00c0bfc8) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = puVar1[2];
        }
        uVar8 = CONCAT44(iVar5,uVar2);
        pcVar7 = "(%d:%d?)%x ";
      }
      FID_conflict__wprintf(pcVar7,iVar4,uVar8);
LAB_006f470a:
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4);
  }
  FID_conflict__wprintf("\n");
  return 0;
}

