
void FUN_0071d5a0(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float10 fVar6;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3 != param_2) {
    for (local_c = *(int *)(in_ECX + 8); local_c != 0; local_c = *(int *)(local_c + 0xc)) {
      local_10 = *(int *)(local_c + 4);
      puVar3 = (undefined4 *)(*(int *)(param_1 + 4) + param_2 * 8);
      iVar2 = ((int)*(undefined4 **)(param_1 + 8) - *(int *)(param_1 + 4) >> 3) - param_2;
      local_8 = 1;
      puVar4 = puVar3;
      if (puVar3 != *(undefined4 **)(param_1 + 8)) {
        do {
          local_24 = *puVar3;
          local_20 = puVar3[1];
          local_1c = local_8;
          local_18 = iVar2;
          if (*(char *)(local_10 + 1) == '\x02') {
            fVar5 = (float10)FUN_0071de00(&local_24,param_3);
            fVar6 = (float10)local_8;
            if (local_8 < 0) {
              fVar6 = fVar6 + (float10)4294967296.0;
            }
            if (fVar6 == fVar5) {
              *puVar4 = *puVar3;
              puVar4[1] = puVar3[1];
LAB_0071d663:
              puVar4 = puVar4 + 2;
            }
          }
          else {
            cVar1 = FUN_0071d8f0(&local_24,param_3);
            if (cVar1 != '\0') {
              *puVar4 = *puVar3;
              puVar4[1] = puVar3[1];
              goto LAB_0071d663;
            }
          }
          local_8 = local_8 + 1;
          puVar3 = puVar3 + 2;
        } while (puVar3 != *(undefined4 **)(param_1 + 8));
      }
      *(undefined4 **)(param_1 + 8) = puVar4;
    }
  }
  return;
}

