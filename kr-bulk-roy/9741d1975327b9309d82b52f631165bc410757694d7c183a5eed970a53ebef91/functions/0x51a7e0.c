
/* WARNING: Removing unreachable block (ram,0x0051a8c8) */
/* WARNING: Removing unreachable block (ram,0x0051a8d8) */
/* WARNING: Removing unreachable block (ram,0x0051a8e1) */
/* WARNING: Removing unreachable block (ram,0x0051a8e4) */
/* WARNING: Removing unreachable block (ram,0x0051a8d4) */
/* WARNING: Removing unreachable block (ram,0x0051a8f2) */
/* WARNING: Removing unreachable block (ram,0x0051a902) */
/* WARNING: Removing unreachable block (ram,0x0051a90d) */
/* WARNING: Removing unreachable block (ram,0x0051a909) */
/* WARNING: Removing unreachable block (ram,0x0051a8fd) */
/* WARNING: Removing unreachable block (ram,0x0051a910) */

void FUN_0051a7e0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091712d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_2 + 0x55) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0051b140(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar8 = (int *)*param_2;
  if (*(char *)((int)piVar8 + 0x55) == '\0') {
    if (*(char *)(param_2[2] + 0x55) == '\0') {
      piVar8 = (int *)param_2[2];
    }
  }
  else {
    piVar8 = (int *)param_2[2];
  }
  piVar7 = (int *)param_2[1];
  if (*(char *)((int)piVar8 + 0x55) == '\0') {
    piVar8[1] = (int)piVar7;
  }
  if ((int *)DAT_00fe3704[1] == param_2) {
    DAT_00fe3704[1] = piVar8;
  }
  else if ((int *)*piVar7 == param_2) {
    *piVar7 = (int)piVar8;
  }
  else {
    piVar7[2] = (int)piVar8;
  }
  if ((int *)*DAT_00fe3704 == param_2) {
    piVar6 = piVar7;
    if (*(char *)((int)piVar8 + 0x55) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x55);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x55);
        piVar6 = piVar4;
      }
    }
    *DAT_00fe3704 = piVar6;
  }
  if ((int *)DAT_00fe3704[2] == param_2) {
    if (*(char *)((int)piVar8 + 0x55) == '\0') {
      uVar5 = FUN_00532d50();
      DAT_00fe3704[2] = uVar5;
    }
    else {
      DAT_00fe3704[2] = piVar7;
    }
  }
  if ((char)param_2[0x15] == '\x01') {
    if (piVar8 != (int *)DAT_00fe3704[1]) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[0x15] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[0x15] == '\0') {
            *(undefined1 *)(piVar7 + 0x15) = 1;
            *(undefined1 *)(piVar6 + 0x15) = 0;
            FUN_0051aec0();
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x55) == '\0') {
            if ((*(char *)(*piVar7 + 0x54) != '\x01') || (*(char *)(piVar7[2] + 0x54) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x54) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x54) = 1;
                *(undefined1 *)(piVar7 + 0x15) = 0;
                FUN_0051af10();
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 0x15) = (char)piVar6[0x15];
              *(undefined1 *)(piVar6 + 0x15) = 1;
              *(undefined1 *)(piVar7[2] + 0x54) = 1;
              FUN_0051aec0();
              break;
            }
LAB_0051a9e5:
            *(undefined1 *)(piVar7 + 0x15) = 0;
          }
        }
        else {
          if ((char)piVar7[0x15] == '\0') {
            *(undefined1 *)(piVar7 + 0x15) = 1;
            *(undefined1 *)(piVar6 + 0x15) = 0;
            FUN_0051af10();
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x55) == '\0') {
            if ((*(char *)(piVar7[2] + 0x54) == '\x01') && (*(char *)(*piVar7 + 0x54) == '\x01'))
            goto LAB_0051a9e5;
            if (*(char *)(*piVar7 + 0x54) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x54) = 1;
              *(undefined1 *)(piVar7 + 0x15) = 0;
              FUN_0051aec0();
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 0x15) = (char)piVar6[0x15];
            *(undefined1 *)(piVar6 + 0x15) = 1;
            *(undefined1 *)(*piVar7 + 0x54) = 1;
            FUN_0051af10();
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != (int *)DAT_00fe3704[1]);
    }
    *(undefined1 *)(piVar8 + 0x15) = 1;
  }
  local_8 = 1;
  FUN_00537240(param_2 + 0xc);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00825810(*(undefined4 *)param_2[9],(undefined4 *)param_2[9]);
  FUN_0089120c(param_2[9]);
  iVar3 = param_2[4];
  if (iVar3 != 0) {
    FUN_0089120c(iVar3);
  }
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  FUN_0089120c(param_2);
  if (DAT_00fe3708 != 0) {
    DAT_00fe3708 = DAT_00fe3708 + -1;
  }
  *param_1 = param_2;
  ExceptionList = local_10;
  return;
}

