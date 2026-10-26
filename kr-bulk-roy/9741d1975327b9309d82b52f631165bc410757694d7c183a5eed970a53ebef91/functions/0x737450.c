
undefined4 FUN_00737450(void)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  HCURSOR hCursor;
  int *local_8;
  
  if (in_EAX[10] == 0) {
    SetCursor((HCURSOR)0x0);
    piVar1 = (int *)*in_EAX;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))(piVar1,0);
    }
    return 1;
  }
  if (((in_EAX[9] != 0) && (in_EAX[8] != 0)) && (*(int *)(in_EAX[8] + 0x30) != 0)) {
    SetCursor((HCURSOR)0x0);
    piVar1 = (int *)*in_EAX;
    if (piVar1 != (int *)0x0) {
      if (*(int *)(in_EAX[8] + 4) != 0) {
        piVar1 = (int *)(**(code **)(**(int **)(in_EAX[8] + 0x30) + 0x10))();
        iVar2 = (**(code **)(*piVar1 + 0x48))(piVar1,0,&local_8);
        if (iVar2 < 0) {
          return 0;
        }
        (**(code **)(*(int *)*in_EAX + 0x28))
                  ((int *)*in_EAX,*(undefined4 *)(in_EAX[8] + 0xc),*(undefined4 *)(in_EAX[8] + 0x10)
                   ,local_8);
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 8))(local_8);
          local_8 = (int *)0x0;
        }
        (**(code **)(*(int *)*in_EAX + 0x30))((int *)*in_EAX,1);
        return 1;
      }
      (**(code **)(*piVar1 + 0x30))(piVar1,0);
    }
    return 1;
  }
  hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  SetCursor(hCursor);
  return 0;
}

