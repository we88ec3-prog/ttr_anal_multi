
/* WARNING: Removing unreachable block (ram,0x004faeed) */
/* WARNING: Removing unreachable block (ram,0x004faefd) */
/* WARNING: Removing unreachable block (ram,0x004faf09) */
/* WARNING: Removing unreachable block (ram,0x004faf0c) */
/* WARNING: Removing unreachable block (ram,0x004faef9) */
/* WARNING: Removing unreachable block (ram,0x004faf1a) */
/* WARNING: Removing unreachable block (ram,0x004faf2a) */
/* WARNING: Removing unreachable block (ram,0x004faf35) */
/* WARNING: Removing unreachable block (ram,0x004faf31) */
/* WARNING: Removing unreachable block (ram,0x004faf25) */
/* WARNING: Removing unreachable block (ram,0x004faf38) */

void FUN_004fae10(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(char *)((int)param_2 + 0xcd) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_004fb2c0();
  piVar4 = (int *)*param_2;
  if (*(char *)((int)piVar4 + 0xcd) == '\0') {
    if (*(char *)(param_2[2] + 0xcd) == '\0') {
      piVar4 = (int *)param_2[2];
    }
  }
  else {
    piVar4 = (int *)param_2[2];
  }
  piVar3 = (int *)param_2[1];
  if (*(char *)((int)piVar4 + 0xcd) == '\0') {
    piVar4[1] = (int)piVar3;
  }
  if ((int *)DAT_00fe1904[1] == param_2) {
    DAT_00fe1904[1] = piVar4;
  }
  else if ((int *)*piVar3 == param_2) {
    *piVar3 = (int)piVar4;
  }
  else {
    piVar3[2] = (int)piVar4;
  }
  if ((int *)*DAT_00fe1904 == param_2) {
    piVar1 = piVar3;
    if (*(char *)((int)piVar4 + 0xcd) == '\0') {
      piVar1 = (int *)FUN_004fb2a0();
    }
    *DAT_00fe1904 = piVar1;
  }
  if ((int *)DAT_00fe1904[2] == param_2) {
    if (*(char *)((int)piVar4 + 0xcd) == '\0') {
      uVar2 = FUN_004fb280();
      DAT_00fe1904[2] = uVar2;
    }
    else {
      DAT_00fe1904[2] = piVar3;
    }
  }
  if ((char)param_2[0x33] == '\x01') {
    if (piVar4 != (int *)DAT_00fe1904[1]) {
      do {
        piVar1 = piVar3;
        if ((char)piVar4[0x33] != '\x01') break;
        piVar3 = (int *)*piVar1;
        if (piVar4 == piVar3) {
          piVar3 = (int *)piVar1[2];
          if ((char)piVar3[0x33] == '\0') {
            *(undefined1 *)(piVar3 + 0x33) = 1;
            *(undefined1 *)(piVar1 + 0x33) = 0;
            FUN_004fb1c0(&DAT_00fe1900);
            piVar3 = (int *)piVar1[2];
          }
          if (*(char *)((int)piVar3 + 0xcd) == '\0') {
            if ((*(char *)(*piVar3 + 0xcc) != '\x01') || (*(char *)(piVar3[2] + 0xcc) != '\x01')) {
              if (*(char *)(piVar3[2] + 0xcc) == '\x01') {
                *(undefined1 *)(*piVar3 + 0xcc) = 1;
                *(undefined1 *)(piVar3 + 0x33) = 0;
                FUN_004fb220(&DAT_00fe1900);
                piVar3 = (int *)piVar1[2];
              }
              *(char *)(piVar3 + 0x33) = (char)piVar1[0x33];
              *(undefined1 *)(piVar1 + 0x33) = 1;
              *(undefined1 *)(piVar3[2] + 0xcc) = 1;
              FUN_004fb1c0(&DAT_00fe1900);
              break;
            }
LAB_004fb079:
            *(undefined1 *)(piVar3 + 0x33) = 0;
          }
        }
        else {
          if ((char)piVar3[0x33] == '\0') {
            *(undefined1 *)(piVar3 + 0x33) = 1;
            *(undefined1 *)(piVar1 + 0x33) = 0;
            FUN_004fb220(&DAT_00fe1900);
            piVar3 = (int *)*piVar1;
          }
          if (*(char *)((int)piVar3 + 0xcd) == '\0') {
            if ((*(char *)(piVar3[2] + 0xcc) == '\x01') && (*(char *)(*piVar3 + 0xcc) == '\x01'))
            goto LAB_004fb079;
            if (*(char *)(*piVar3 + 0xcc) == '\x01') {
              *(undefined1 *)(piVar3[2] + 0xcc) = 1;
              *(undefined1 *)(piVar3 + 0x33) = 0;
              FUN_004fb1c0(&DAT_00fe1900);
              piVar3 = (int *)*piVar1;
            }
            *(char *)(piVar3 + 0x33) = (char)piVar1[0x33];
            *(undefined1 *)(piVar1 + 0x33) = 1;
            *(undefined1 *)(*piVar3 + 0xcc) = 1;
            FUN_004fb220(&DAT_00fe1900);
            break;
          }
        }
        piVar3 = (int *)piVar1[1];
        piVar4 = piVar1;
      } while (piVar1 != (int *)DAT_00fe1904[1]);
    }
    *(undefined1 *)(piVar4 + 0x33) = 1;
  }
  _eh_vector_destructor_iterator_(param_2 + 6,0x24,5,FUN_004fa440);
  FUN_0089120c(param_2);
  if (DAT_00fe1908 != 0) {
    DAT_00fe1908 = DAT_00fe1908 + -1;
  }
  *param_1 = param_2;
  return;
}

