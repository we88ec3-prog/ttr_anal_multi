
/* WARNING: Removing unreachable block (ram,0x006cf368) */
/* WARNING: Removing unreachable block (ram,0x006cf378) */
/* WARNING: Removing unreachable block (ram,0x006cf381) */
/* WARNING: Removing unreachable block (ram,0x006cf384) */
/* WARNING: Removing unreachable block (ram,0x006cf374) */
/* WARNING: Removing unreachable block (ram,0x006cf392) */
/* WARNING: Removing unreachable block (ram,0x006cf3a2) */
/* WARNING: Removing unreachable block (ram,0x006cf3ad) */
/* WARNING: Removing unreachable block (ram,0x006cf3a9) */
/* WARNING: Removing unreachable block (ram,0x006cf39d) */
/* WARNING: Removing unreachable block (ram,0x006cf3b0) */

void FUN_006cf2a0(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00717a50();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x2d) == '\0') {
    if (*(char *)(param_2[2] + 0x2d) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x2d) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fc172c[1] == param_2) {
    DAT_00fc172c[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fc172c == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x2d) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x2d);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x2d);
        piVar5 = piVar3;
      }
    }
    *DAT_00fc172c = piVar5;
  }
  if ((int *)DAT_00fc172c[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x2d) == '\0') {
      uVar4 = FUN_00585370();
      DAT_00fc172c[2] = uVar4;
    }
    else {
      DAT_00fc172c[2] = piVar6;
    }
  }
  if ((char)param_2[0xb] == '\x01') {
    if (piVar7 != (int *)DAT_00fc172c[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0xb] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0xb] == '\0') {
            *(undefined1 *)(piVar6 + 0xb) = 1;
            *(undefined1 *)(piVar5 + 0xb) = 0;
            FUN_006cf560();
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x2d) == '\0') {
            if ((*(char *)(*piVar6 + 0x2c) != '\x01') || (*(char *)(piVar6[2] + 0x2c) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x2c) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x2c) = 1;
                *(undefined1 *)(piVar6 + 0xb) = 0;
                FUN_006cf5b0();
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0xb) = (char)piVar5[0xb];
              *(undefined1 *)(piVar5 + 0xb) = 1;
              *(undefined1 *)(piVar6[2] + 0x2c) = 1;
              FUN_006cf560();
              break;
            }
LAB_006cf47b:
            *(undefined1 *)(piVar6 + 0xb) = 0;
          }
        }
        else {
          if ((char)piVar6[0xb] == '\0') {
            *(undefined1 *)(piVar6 + 0xb) = 1;
            *(undefined1 *)(piVar5 + 0xb) = 0;
            FUN_006cf5b0();
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x2d) == '\0') {
            if ((*(char *)(piVar6[2] + 0x2c) == '\x01') && (*(char *)(*piVar6 + 0x2c) == '\x01'))
            goto LAB_006cf47b;
            if (*(char *)(*piVar6 + 0x2c) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x2c) = 1;
              *(undefined1 *)(piVar6 + 0xb) = 0;
              FUN_006cf560();
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0xb) = (char)piVar5[0xb];
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(*piVar6 + 0x2c) = 1;
            FUN_006cf5b0();
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fc172c[1]);
    }
    *(undefined1 *)(piVar7 + 0xb) = 1;
  }
  if (0xf < (uint)param_2[8]) {
    FUN_0089120c(param_2[3]);
  }
  param_2[8] = 0xf;
  param_2[7] = 0;
  *(undefined1 *)(param_2 + 3) = 0;
  FUN_0089120c(param_2);
  if (DAT_00fc1730 != 0) {
    DAT_00fc1730 = DAT_00fc1730 + -1;
  }
  *param_1 = param_2;
  return;
}

