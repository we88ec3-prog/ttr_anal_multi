
char * FUN_0072a340(uint param_1)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int unaff_EDI;
  uint local_14;
  uint local_10;
  uint local_c;
  char local_6;
  char local_5;
  
  uVar2 = *(uint *)(unaff_EDI + 0x6c);
  local_c = *(uint *)(unaff_EDI + 0x7c);
  pcVar4 = (char *)(*(int *)(unaff_EDI + 0x38) + uVar2);
  pcVar3 = *(char **)(unaff_EDI + 0x78);
  if (*(int *)(unaff_EDI + 0x2c) - 0x106U < uVar2) {
    local_14 = (uVar2 - *(int *)(unaff_EDI + 0x2c)) + 0x106;
  }
  else {
    local_14 = 0;
  }
  local_5 = pcVar4[(int)(pcVar3 + -1)];
  local_6 = pcVar4[(int)pcVar3];
  pcVar1 = pcVar4 + 0x102;
  if (*(char **)(unaff_EDI + 0x8c) <= pcVar3) {
    local_c = local_c >> 2;
  }
  local_10 = *(uint *)(unaff_EDI + 0x90);
  if (*(uint *)(unaff_EDI + 0x74) < *(uint *)(unaff_EDI + 0x90)) {
    local_10 = *(uint *)(unaff_EDI + 0x74);
  }
  do {
    pcVar7 = (char *)(*(int *)(unaff_EDI + 0x38) + param_1);
    if ((((pcVar7[(int)pcVar3] == local_6) && (pcVar7[(int)(pcVar3 + -1)] == local_5)) &&
        (*pcVar7 == *pcVar4)) && (pcVar7[1] == pcVar4[1])) {
      pcVar7 = pcVar7 + 2;
      pcVar5 = pcVar4 + 2;
      while (((((pcVar6 = pcVar5 + 1, pcVar5[1] == pcVar7[1] &&
                (pcVar6 = pcVar5 + 2, pcVar5[2] == pcVar7[2])) &&
               ((pcVar6 = pcVar5 + 3, pcVar5[3] == pcVar7[3] &&
                ((pcVar6 = pcVar5 + 4, pcVar5[4] == pcVar7[4] &&
                 (pcVar6 = pcVar5 + 5, pcVar5[5] == pcVar7[5])))))) &&
              (pcVar6 = pcVar5 + 6, pcVar5[6] == pcVar7[6])) &&
             (pcVar6 = pcVar5 + 7, pcVar5[7] == pcVar7[7]))) {
        pcVar6 = pcVar5 + 8;
        pcVar7 = pcVar7 + 8;
        if ((pcVar5[8] != *pcVar7) || (pcVar5 = pcVar6, pcVar1 <= pcVar6)) break;
      }
      pcVar7 = pcVar6 + (0x102 - (int)pcVar1);
      if ((int)pcVar3 < (int)pcVar7) {
        *(uint *)(unaff_EDI + 0x70) = param_1;
        if ((int)local_10 <= (int)pcVar7) {
LAB_0072a48a:
          if (*(char **)(unaff_EDI + 0x74) < pcVar7) {
            pcVar7 = *(char **)(unaff_EDI + 0x74);
          }
          return pcVar7;
        }
        local_5 = pcVar4[(int)(pcVar6 + (0x101 - (int)pcVar1))];
        local_6 = pcVar4[(int)pcVar7];
        pcVar3 = pcVar7;
      }
    }
    pcVar7 = pcVar3;
    param_1 = (uint)*(ushort *)
                     (*(int *)(unaff_EDI + 0x40) + (*(uint *)(unaff_EDI + 0x34) & param_1) * 2);
    if ((param_1 <= local_14) || (local_c = local_c - 1, pcVar3 = pcVar7, local_c == 0))
    goto LAB_0072a48a;
  } while( true );
}

