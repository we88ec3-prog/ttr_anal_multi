
void FUN_0077eb40(undefined4 param_1)

{
  int in_ECX;
  int *piVar1;
  undefined4 *puVar2;
  
  if (*(int *)(in_ECX + 100) == 0) {
    piVar1 = *(int **)(in_ECX + 0xd8);
    if (piVar1 != *(int **)(in_ECX + 0xdc)) {
      do {
        if (((int *)*piVar1)[0x1c] == 0) {
          (**(code **)(*(int *)*piVar1 + 0x24))(in_ECX + 0x94,param_1);
        }
        piVar1 = piVar1 + 1;
      } while (piVar1 != *(int **)(in_ECX + 0xdc));
    }
    puVar2 = *(undefined4 **)(in_ECX + 200);
    if (puVar2 != *(undefined4 **)(in_ECX + 0xcc)) {
      do {
        (**(code **)(*(int *)*puVar2 + 0x28))(param_1);
        puVar2 = puVar2 + 1;
      } while (puVar2 != *(undefined4 **)(in_ECX + 0xcc));
    }
  }
  return;
}

