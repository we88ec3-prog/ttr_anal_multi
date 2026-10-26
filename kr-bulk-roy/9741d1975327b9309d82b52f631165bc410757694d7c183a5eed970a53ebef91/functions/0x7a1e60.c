
/* WARNING: Removing unreachable block (ram,0x007a1f28) */
/* WARNING: Removing unreachable block (ram,0x007a1f38) */
/* WARNING: Removing unreachable block (ram,0x007a1f41) */
/* WARNING: Removing unreachable block (ram,0x007a1f44) */
/* WARNING: Removing unreachable block (ram,0x007a1f34) */
/* WARNING: Removing unreachable block (ram,0x007a1f52) */
/* WARNING: Removing unreachable block (ram,0x007a1f62) */
/* WARNING: Removing unreachable block (ram,0x007a1f6d) */
/* WARNING: Removing unreachable block (ram,0x007a1f69) */
/* WARNING: Removing unreachable block (ram,0x007a1f5d) */
/* WARNING: Removing unreachable block (ram,0x007a1f70) */

void FUN_007a1e60(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(char *)((int)param_2 + 0x19) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00406870();
  piVar8 = (int *)*param_2;
  if (*(char *)((int)piVar8 + 0x19) == '\0') {
    if (*(char *)(param_2[2] + 0x19) == '\0') {
      piVar8 = (int *)param_2[2];
    }
  }
  else {
    piVar8 = (int *)param_2[2];
  }
  piVar7 = (int *)param_2[1];
  if (*(char *)((int)piVar8 + 0x19) == '\0') {
    piVar8[1] = (int)piVar7;
  }
  if ((int *)DAT_00fc0e94[1] == param_2) {
    DAT_00fc0e94[1] = piVar8;
  }
  else if ((int *)*piVar7 == param_2) {
    *piVar7 = (int)piVar8;
  }
  else {
    piVar7[2] = (int)piVar8;
  }
  if ((int *)*DAT_00fc0e94 == param_2) {
    piVar6 = piVar7;
    if (*(char *)((int)piVar8 + 0x19) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x19);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x19);
        piVar6 = piVar4;
      }
    }
    *DAT_00fc0e94 = piVar6;
  }
  if ((int *)DAT_00fc0e94[2] == param_2) {
    if (*(char *)((int)piVar8 + 0x19) == '\0') {
      uVar5 = FUN_00517350();
      DAT_00fc0e94[2] = uVar5;
    }
    else {
      DAT_00fc0e94[2] = piVar7;
    }
  }
  if ((char)param_2[6] == '\x01') {
    if (piVar8 != (int *)DAT_00fc0e94[1]) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[6] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[6] == '\0') {
            *(undefined1 *)(piVar7 + 6) = 1;
            *(undefined1 *)(piVar6 + 6) = 0;
            FUN_00407e10(&DAT_00fc0e90);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x19) == '\0') {
            if ((*(char *)(*piVar7 + 0x18) != '\x01') || (*(char *)(piVar7[2] + 0x18) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x18) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x18) = 1;
                *(undefined1 *)(piVar7 + 6) = 0;
                FUN_00852420(&DAT_00fc0e90);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 6) = (char)piVar6[6];
              *(undefined1 *)(piVar6 + 6) = 1;
              *(undefined1 *)(piVar7[2] + 0x18) = 1;
              FUN_00407e10(&DAT_00fc0e90);
              break;
            }
LAB_007a2057:
            *(undefined1 *)(piVar7 + 6) = 0;
          }
        }
        else {
          if ((char)piVar7[6] == '\0') {
            *(undefined1 *)(piVar7 + 6) = 1;
            *(undefined1 *)(piVar6 + 6) = 0;
            FUN_00852420(&DAT_00fc0e90);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x19) == '\0') {
            if ((*(char *)(piVar7[2] + 0x18) == '\x01') && (*(char *)(*piVar7 + 0x18) == '\x01'))
            goto LAB_007a2057;
            if (*(char *)(*piVar7 + 0x18) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x18) = 1;
              *(undefined1 *)(piVar7 + 6) = 0;
              FUN_00407e10(&DAT_00fc0e90);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 6) = (char)piVar6[6];
            *(undefined1 *)(piVar6 + 6) = 1;
            *(undefined1 *)(*piVar7 + 0x18) = 1;
            FUN_00852420(&DAT_00fc0e90);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != (int *)DAT_00fc0e94[1]);
    }
    *(undefined1 *)(piVar8 + 6) = 1;
  }
  piVar8 = (int *)param_2[5];
  if (piVar8 != (int *)0x0) {
    LOCK();
    iVar3 = piVar8[1] + -1;
    piVar8[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)*piVar8)();
      LOCK();
      iVar3 = piVar8[2] + -1;
      piVar8[2] = iVar3;
      UNLOCK();
      if (iVar3 == 0) {
        (**(code **)(*piVar8 + 4))();
      }
    }
  }
  FUN_0089120c(param_2);
  if (DAT_00fc0e98 != 0) {
    DAT_00fc0e98 = DAT_00fc0e98 + -1;
  }
  *param_1 = param_2;
  return;
}

