
void FUN_00539610(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  
  puVar1 = in_EAX + 4;
  if (7 < (uint)in_EAX[5]) {
    in_EAX = (undefined4 *)*in_EAX;
  }
  FUN_00466df0(param_1,in_EAX,*puVar1);
  return;
}

