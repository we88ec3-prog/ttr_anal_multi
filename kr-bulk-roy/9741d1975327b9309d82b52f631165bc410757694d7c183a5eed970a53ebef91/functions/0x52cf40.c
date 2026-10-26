
void FUN_0052cf40(int *param_1)

{
  undefined4 *in_EAX;
  int in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x39) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[4] < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x39) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(in_ECX + 4)) && ((int)puVar3[4] <= *param_1)) {
    *in_EAX = puVar3;
    return;
  }
  *in_EAX = *(undefined4 **)(in_ECX + 4);
  return;
}

