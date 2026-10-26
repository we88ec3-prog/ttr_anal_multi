
void FUN_008cef50(void)

{
  uint uVar1;
  uint uVar2;
  int *in_EAX;
  int *piVar3;
  uint *puVar4;
  int *unaff_ESI;
  int iVar5;
  int local_14;
  int local_10;
  
  local_14 = *in_EAX;
  if (local_14 != 0) {
    puVar4 = (uint *)(in_EAX[2] + 0x10);
    do {
      if ((((((char)puVar4[1] == '\x02') || ((char)puVar4[1] == -2)) ||
           (*(char *)((int)puVar4 + 5) == '\x02')) || (*(char *)((int)puVar4 + 5) == -2)) &&
         ((*puVar4 & 0x10) == 0)) {
        uVar1 = puVar4[3];
        local_10 = *unaff_ESI;
        if (local_10 != 0) {
          piVar3 = unaff_ESI + 3;
          do {
            if ((int)(uVar1 - piVar3[1]) < -unaff_ESI[0x207]) break;
            if (((int)uVar1 <= *piVar3 + unaff_ESI[0x207]) &&
               (((char)unaff_ESI[0x208] != '\0' || ((int)(uVar1 - piVar3[1]) <= unaff_ESI[0x206]))))
            {
              uVar2 = piVar3[4];
              *puVar4 = *puVar4 | 0x30;
              puVar4[5] = uVar2;
            }
            local_10 = local_10 + -1;
            piVar3 = piVar3 + 8;
          } while (local_10 != 0);
        }
        iVar5 = unaff_ESI[0x81];
        piVar3 = unaff_ESI + iVar5 * 8 + 0x7d;
        for (; iVar5 != 0; iVar5 = iVar5 + -1) {
          if ((int)(piVar3[-1] - uVar1) < -unaff_ESI[0x207]) break;
          if ((*piVar3 - unaff_ESI[0x207] <= (int)uVar1) &&
             (((char)unaff_ESI[0x208] != '\0' || ((int)(piVar3[-1] - uVar1) < unaff_ESI[0x206])))) {
            uVar2 = piVar3[4];
            *puVar4 = *puVar4 | 0x30;
            puVar4[5] = uVar2;
          }
          piVar3 = piVar3 + -8;
        }
      }
      local_14 = local_14 + -1;
      puVar4 = puVar4 + 10;
    } while (local_14 != 0);
  }
  return;
}

