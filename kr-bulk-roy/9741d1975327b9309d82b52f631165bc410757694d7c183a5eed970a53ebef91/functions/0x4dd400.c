
void FUN_004dd400(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (((int)param_3[1] < (int)puVar1[5]) ||
         (((int)param_3[1] <= (int)puVar1[5] && (*param_3 <= (uint)puVar1[4])))) {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      else {
        puVar2 = (undefined4 *)puVar1[2];
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if (puVar3 != *(undefined4 **)(param_1 + 4)) {
    if (((int)puVar3[5] <= (int)param_3[1]) &&
       (((int)puVar3[5] < (int)param_3[1] || ((uint)puVar3[4] <= *param_3)))) {
      *param_2 = puVar3;
      return;
    }
  }
  *param_2 = *(undefined4 **)(param_1 + 4);
  return;
}

