game_state = Game::GameState
States = Game::Constants::States

Game::SaveState.load do |save_state|
  # puts "load"
  game_state.state = States::EGG
  # game_state.animation_fps = 3
  game_state.transition_to(States::HATCHING, 1000)
end

Game::Events.state_change(States::EGG, States::HATCHING) do
  # puts "egg to hatching"
  # game_state.animation_fps = 10
  # game_state.state = States::HATCHED
  # game_state.message = "I'm hatching"
  game_state.transition_to(States::HATCHED, 1000)
end

Game::Events.state_change(States::HATCHING, States::HATCHED) do
  # puts "hatching to hatched"
  game_state.message = "Hello from mruby!"
end

while true do
  ESP32::System.delay(10000)
end