(*
 * @file The_Descent.fs
 * @author Ladjouzi Rachid (RashidLadj@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 *)

open System

(* game loop *)
while true do
    let mutable index = -1
    let mutable maxHeight = -1
    for i in 0 .. 8 - 1 do   
        let mountainH = int(Console.In.ReadLine()) (* represents the height of one mountain. *)
        if (mountainH > maxHeight) then
            index <- i
            maxHeight <- mountainH

    printfn "%i" index (* The index of the mountain to fire on. *)