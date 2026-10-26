
/* WARNING: Removing unreachable block (ram,0x0046ee78) */
/* WARNING: Removing unreachable block (ram,0x0046ee88) */
/* WARNING: Removing unreachable block (ram,0x0046ee91) */
/* WARNING: Removing unreachable block (ram,0x0046ee94) */
/* WARNING: Removing unreachable block (ram,0x0046ee84) */
/* WARNING: Removing unreachable block (ram,0x0046eea2) */
/* WARNING: Removing unreachable block (ram,0x0046eeb2) */
/* WARNING: Removing unreachable block (ram,0x0046eebd) */
/* WARNING: Removing unreachable block (ram,0x0046eeb9) */
/* WARNING: Removing unreachable block (ram,0x0046eead) */
/* WARNING: Removing unreachable block (ram,0x0046eec0) */

void FUN_0046edb0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x51) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0051f3c0();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x51) == '\0') {
    if (*(char *)(param_2[2] + 0x51) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x51) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fc0d78[1] == param_2) {
    DAT_00fc0d78[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fc0d78 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x51) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x51);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x51);
        piVar5 = piVar3;
      }
    }
    *DAT_00fc0d78 = piVar5;
  }
  if ((int *)DAT_00fc0d78[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x51) == '\0') {
      uVar4 = FUN_00835380();
      DAT_00fc0d78[2] = uVar4;
    }
    else {
      DAT_00fc0d78[2] = piVar6;
    }
  }
  if ((char)param_2[0x14] == '\x01') {
    if (piVar7 != (int *)DAT_00fc0d78[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x14] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x14] == '\0') {
            *(undefined1 *)(piVar6 + 0x14) = 1;
            *(undefined1 *)(piVar5 + 0x14) = 0;
            FUN_0046f160();
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x51) == '\0') {
            if ((*(char *)(*piVar6 + 0x50) != '\x01') || (*(char *)(piVar6[2] + 0x50) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x50) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x50) = 1;
                *(undefined1 *)(piVar6 + 0x14) = 0;
                FUN_0046f1b0();
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x14) = (char)piVar5[0x14];
              *(undefined1 *)(piVar5 + 0x14) = 1;
              *(undefined1 *)(piVar6[2] + 0x50) = 1;
              FUN_0046f160();
              break;
            }
LAB_0046ef95:
            *(undefined1 *)(piVar6 + 0x14) = 0;
          }
        }
        else {
          if ((char)piVar6[0x14] == '\0') {
            *(undefined1 *)(piVar6 + 0x14) = 1;
            *(undefined1 *)(piVar5 + 0x14) = 0;
            FUN_0046f1b0();
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x51) == '\0') {
            if ((*(char *)(piVar6[2] + 0x50) == '\x01') && (*(char *)(*piVar6 + 0x50) == '\x01'))
            goto LAB_0046ef95;
            if (*(char *)(*piVar6 + 0x50) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x50) = 1;
              *(undefined1 *)(piVar6 + 0x14) = 0;
              FUN_0046f160();
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x14) = (char)piVar5[0x14];
            *(undefined1 *)(piVar5 + 0x14) = 1;
            *(undefined1 *)(*piVar6 + 0x50) = 1;
            FUN_0046f1b0();
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fc0d78[1]);
    }
    *(undefined1 *)(piVar7 + 0x14) = 1;
  }
  if (0xf < (uint)param_2[0x11]) {
    FUN_0089120c(param_2[0xc]);
  }
  param_2[0x11] = 0xf;
  param_2[0x10] = 0;
  *(undefined1 *)(param_2 + 0xc) = 0;
  if (0xf < (uint)param_2[10]) {
    FUN_0089120c(param_2[5]);
  }
  param_2[10] = 0xf;
  param_2[9] = 0;
  *(undefined1 *)(param_2 + 5) = 0;
  FUN_0089120c(param_2);
  if (DAT_00fc0d7c != 0) {
    DAT_00fc0d7c = DAT_00fc0d7c + -1;
  }
  *param_1 = param_2;
  return;
}

