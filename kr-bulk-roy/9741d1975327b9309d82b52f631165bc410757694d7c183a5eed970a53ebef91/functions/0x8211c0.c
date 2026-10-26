
/* WARNING: Removing unreachable block (ram,0x00821288) */
/* WARNING: Removing unreachable block (ram,0x00821298) */
/* WARNING: Removing unreachable block (ram,0x008212a1) */
/* WARNING: Removing unreachable block (ram,0x008212a4) */
/* WARNING: Removing unreachable block (ram,0x00821294) */
/* WARNING: Removing unreachable block (ram,0x008212b2) */
/* WARNING: Removing unreachable block (ram,0x008212c2) */
/* WARNING: Removing unreachable block (ram,0x008212cd) */
/* WARNING: Removing unreachable block (ram,0x008212c9) */
/* WARNING: Removing unreachable block (ram,0x008212bd) */
/* WARNING: Removing unreachable block (ram,0x008212d0) */

void FUN_008211c0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x19) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00406870();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x19) == '\0') {
    if (*(char *)(param_2[2] + 0x19) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x19) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fb7bd4[1] == param_2) {
    DAT_00fb7bd4[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fb7bd4 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x19) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x19);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x19);
        piVar5 = piVar3;
      }
    }
    *DAT_00fb7bd4 = piVar5;
  }
  if ((int *)DAT_00fb7bd4[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x19) == '\0') {
      uVar4 = FUN_00517350();
      DAT_00fb7bd4[2] = uVar4;
    }
    else {
      DAT_00fb7bd4[2] = piVar6;
    }
  }
  if ((char)param_2[6] == '\x01') {
    if (piVar7 != (int *)DAT_00fb7bd4[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[6] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[6] == '\0') {
            *(undefined1 *)(piVar6 + 6) = 1;
            *(undefined1 *)(piVar5 + 6) = 0;
            FUN_00407e10(&DAT_00fb7bd0);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x19) == '\0') {
            if ((*(char *)(*piVar6 + 0x18) != '\x01') || (*(char *)(piVar6[2] + 0x18) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x18) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x18) = 1;
                *(undefined1 *)(piVar6 + 6) = 0;
                FUN_00852420(&DAT_00fb7bd0);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 6) = (char)piVar5[6];
              *(undefined1 *)(piVar5 + 6) = 1;
              *(undefined1 *)(piVar6[2] + 0x18) = 1;
              FUN_00407e10(&DAT_00fb7bd0);
              break;
            }
LAB_008213b7:
            *(undefined1 *)(piVar6 + 6) = 0;
          }
        }
        else {
          if ((char)piVar6[6] == '\0') {
            *(undefined1 *)(piVar6 + 6) = 1;
            *(undefined1 *)(piVar5 + 6) = 0;
            FUN_00852420(&DAT_00fb7bd0);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x19) == '\0') {
            if ((*(char *)(piVar6[2] + 0x18) == '\x01') && (*(char *)(*piVar6 + 0x18) == '\x01'))
            goto LAB_008213b7;
            if (*(char *)(*piVar6 + 0x18) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x18) = 1;
              *(undefined1 *)(piVar6 + 6) = 0;
              FUN_00407e10(&DAT_00fb7bd0);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 6) = (char)piVar5[6];
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(*piVar6 + 0x18) = 1;
            FUN_00852420(&DAT_00fb7bd0);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fb7bd4[1]);
    }
    *(undefined1 *)(piVar7 + 6) = 1;
  }
  FUN_0089120c(param_2);
  if (DAT_00fb7bd8 != 0) {
    DAT_00fb7bd8 = DAT_00fb7bd8 + -1;
  }
  *param_1 = param_2;
  return;
}

